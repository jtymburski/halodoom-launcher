#ifndef NETWORKINFO_H
#define NETWORKINFO_H

#include <QNetworkInterface>
#include <QRegularExpression>
#include <QString>

class NetworkInfo
{
private:
  /* Local network address ordered filters to apply when deciding on the address to return  */
  const static QStringList LOCAL_ADDRESS_FILTERS;

public:
  /* Returns if the address is a valid IPv4 format */
  bool isValidAddress(QString address);

  /* Fetches the local network address, expected in IPv4 format */
  QString localAddress();
};

#endif // NETWORKINFO_H
