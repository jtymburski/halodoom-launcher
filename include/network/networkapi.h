/**
 * @class NetworkAPI
 *
 * Abstraction layer for all network API calls for remote reading and writing of
 * the server environments.
 */
#ifndef NETWORKAPI_H
#define NETWORKAPI_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QVector>
#include <QDebug>

#include "model/gametypes.h"
#include "model/remoteasset.h"
#include "model/remoteserver.h"

class NetworkAPI : public QObject
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  NetworkAPI(QObject *parent = nullptr);

private:
  /* Network abstraction for sending and receiving requests */
  QNetworkAccessManager *network_manager;

  /* Game type translation maps */
  QMap<QString, Map> map_to_id;
  QMap<QString, Mode> mode_to_id;
  QMap<QString, LoadOut> loadout_to_id;

  /* Path and URL properties */
  const static QString API_GET_CONFIG_PATH;
  const static QString API_URL;

signals:
  /* Assets asynchronously received from {@link getConfig()} */
  void assetsReceived(const QVector<RemoteAsset> &assets);

  /* Servers asynchronously received from {@link getConfig()} */
  void serversReceived(const QVector<RemoteServer> &servers);

private slots:
  /* Read and process the response from {@link getConfig()} */
  void readGetConfig(QNetworkReply *reply);

public:
  /* Start an asynchronous fetch of the remote configuration state */
  bool getConfig();
};

#endif // NETWORKAPI_H
