/**
 * @class NetworkAPI
 *
 * Abstraction layer for all network API calls for remote reading and writing of
 * the server environments.
 */
#include "network/networkapi.h"

/* Path and URL properties */
const QString NetworkAPI::API_GET_CONFIG_PATH = QStringLiteral("/halodoom/config");
const QString NetworkAPI::API_URL =
    QStringLiteral("https://9m3yorpgl7.execute-api.us-west-2.amazonaws.com");

/* Constructor, with just the parent */
NetworkAPI::NetworkAPI(QObject *parent) : QObject(parent)
{
  this->network_manager = new QNetworkAccessManager(parent);

  this->map_to_id.insert("floodgulch", Map::FLOOD_GULCH);
  this->map_to_id.insert("ghostship", Map::GHOST_SHIP);
  this->map_to_id.insert("rebellion", Map::REBELLION);
  this->map_to_id.insert("submerged", Map::SUBMERGED);
  this->map_to_id.insert("warehouse", Map::WAREHOUSE);

  this->mode_to_id.insert("fiesta", Mode::FIESTA);
  this->mode_to_id.insert("slayer", Mode::SLAYER);
  this->mode_to_id.insert("shottysnipers", Mode::SHOTTY_SHIPERS);
  this->mode_to_id.insert("swat", Mode::SWAT);
  this->mode_to_id.insert("swords", Mode::SWORDS);
}

/* Read and process the response from {@link getConfig()} */
void NetworkAPI::readGetConfig(QNetworkReply *reply)
{
  // Deserialize to JSON doc
  const QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
  const QJsonObject obj = doc.object();

  // Assets
  const QJsonArray assets_json = obj.value("assets").toArray();
  QVector<RemoteAsset> assets;
  for (const QJsonValue &value : assets_json)
  {
    const QJsonObject asset = value.toObject();
    assets.append(RemoteAsset::Builder()
                  .setHash(asset.value("md5").toString())
                  ->setName(asset.value("name").toString())
                  ->setUrl(asset.value("url").toString())
                  ->setVersion(asset.value("version").toInt())
                  ->build());
  }
  emit assetsReceived(assets);

  // Servers
  const QJsonArray servers_json = obj.value("servers").toArray();
  QVector<RemoteServer> servers;
  for (const QJsonValue &value : servers_json)
  {
    const QJsonObject server = value.toObject();

    // Perform basic validation to confirm the object is the expected model
    QString map_str = server.value("map").toString().toLower();
    QString mode_str = server.value("mode").toString().toLower();
    if(map_to_id.contains(map_str) && mode_to_id.contains(mode_str))
    {
      servers.append(RemoteServer::Builder()
                     .setAddress(server.value("address").toString())
                     ->setId(server.value("id").toString())
                     ->setMapId(map_to_id.value(map_str))
                     ->setModeId(mode_to_id.value(mode_str))
                     ->setName(server.value("name").toString())
                     ->setPort(server.value("port").toString())
                     ->build());
    }
    else
    {
      qWarning() << "[WARNING] Server response config model =" << server << "is not valid";
    }
  }
  emit serversReceived(servers);
}

/* Start an asynchronous fetch of the remote configuration state */
bool NetworkAPI::getConfig()
{
  QNetworkRequest request(QUrl(API_URL + API_GET_CONFIG_PATH));
  request.setSslConfiguration(QSslConfiguration::defaultConfiguration());

  // Start the request
  QNetworkReply *reply = network_manager->get(request);
  //reply->deleteLater();
  connect(reply, &QNetworkReply::finished, this, [=]() { this->readGetConfig(reply); });

  return reply->isRunning();
}
