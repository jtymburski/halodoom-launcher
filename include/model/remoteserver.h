/**
 * @class RemoteServer
 *
 * Remote server for a single running Zandronum remote server, available at the URI.
 */
#ifndef REMOTESERVER_H
#define REMOTESERVER_H

#include <QString>

#include "model/gametypes.h"

class RemoteServer
{
public:
  class Builder;

private:
  /* Private blank constructor, use {@link Builder} */
  RemoteServer() = default;

  /* Server ip address */
  QString address;

  /* Unique identifier for the server */
  QString id;

  /* Map identifier currently running on the server */
  Map map_id;

  /* Mode identifier currently running on the server */
  Mode mode_id;

  /* Loadout identifier currently running on the server */
  LoadOut loadout_id;

  /* Readable name for the active server */
  QString name;

  /* Server port number */
  QString port;

public:
  /* Returns the server IP address */
  QString getAddress() const;

  /* Returns the unique identifier for the server */
  QString getId() const;

  /* Returns the map identifier currently running on the server */
  Map getMapId() const;

  /* Returns the mode identifier currently running on the server */
  Mode getModeId() const;

  /* Returns the loadout identifier currently running on the server */
  LoadOut getLoadOutId() const;

  /* Returns the readable name for the active server */
  QString getName() const;

  /* Returns the server port number */
  QString getPort() const;

  /* Builder nested class for constructing the immutable object */
  class Builder
  {
  private:
    QString address;
    QString id;
    Map map_id;
    Mode mode_id;
    LoadOut loadout_id;
    QString name;
    QString port;

  public:
    RemoteServer build();
    Builder* setAddress(QString address);
    Builder* setId(QString id);
    Builder* setMapId(Map map_id);
    Builder* setModeId(Mode mode_id);
    Builder* setLoadOutId(LoadOut loadout_id);
    Builder* setName(QString name);
    Builder* setPort(QString port);
  };
};

#endif // REMOTESERVER_H
