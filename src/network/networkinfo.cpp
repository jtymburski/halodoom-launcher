#include "network/networkinfo.h"

/* Local network address ordered filters to apply when deciding on the address to return  */
const QStringList NetworkInfo::LOCAL_ADDRESS_FILTERS = {
  "^192\\.",
  "^10\\."
};

/**
 * Returns if the address provided is valid and can be parsed. If this returns true,
 * it is expected that this should be compatible with any network interface.
 */
bool NetworkInfo::isValidAddress(QString address)
{
  QHostAddress validated_address(address);
  return !validated_address.isNull();
}

/**
 * Fetches the local network address, expected in IPv4 format. Today, this only supports
 * connections through the Ethernet or Wifi adapters on the host machine. VM bridges are
 * unsupported.
 */
QString NetworkInfo::localAddress()
{
  QStringList candidate_addresses;

  // Filter through all interfaces to reduce the number of candidates
  QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
  for(auto interface = interfaces.begin(); interface != interfaces.end(); interface++)
  {
    // Only Ethernet and WIFI based interfaces are supported for server broadcast
    if(interface->type() == QNetworkInterface::Ethernet
       || interface->type() == QNetworkInterface::Wifi)
    {
      // Verify the interface is up and can broadcast
      auto required_flags = (QNetworkInterface::IsUp | QNetworkInterface::CanBroadcast);
      if((interface->flags() & required_flags) == required_flags)
      {
        // Run through all addresses under the interface definition
        QList<QNetworkAddressEntry> addresses = interface->addressEntries();
        for(auto address = addresses.begin(); address != addresses.end(); address++)
        {
          // Only IPv4 based addresses are supported for server hosting
          QHostAddress ip_address = address->ip();
          if(!ip_address.isNull() && ip_address.protocol() == QAbstractSocket::IPv4Protocol)
            candidate_addresses.append(ip_address.toString());
        }
      }
    }
  }

  // Sort the list to ensure consistency
  candidate_addresses.sort();

  // Prioritize the filters for finding the preferred address
  for(auto const &filter : LOCAL_ADDRESS_FILTERS)
  {
    QStringList filtered_addresses = candidate_addresses.filter(QRegularExpression(filter));
    if(!filtered_addresses.isEmpty())
      return filtered_addresses.first();
  }

  // Otherwise, just return the first in the list
  return candidate_addresses.isEmpty() ? QString() : candidate_addresses.first();
}
