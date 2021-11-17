/**
 * @class RemoteServer
 *
 * Remote server for a single running Zandronum remote server, available at the URI.
 */
#include "model/remoteserver.h"

/* Returns the server IP address */
QString RemoteServer::getAddress() const
{
  return address;
}

/* Returns the unique identifier for the server */
QString RemoteServer::getId() const
{
  return id;
}

/* Returns the map identifier currently running on the server */
Map RemoteServer::getMapId() const
{
  return map_id;
}

/* Returns the mode identifier currently running on the server */
Mode RemoteServer::getModeId() const
{
  return mode_id;
}

/* Returns the readable name for the active server */
QString RemoteServer::getName() const
{
  return name;
}

/* Returns the server port number */
QString RemoteServer::getPort() const
{
  return port;
}

/**
 * Build the {@link RemoteServer} object from the configured builder.
 * @return built object
 */
RemoteServer RemoteServer::Builder::build()
{
  RemoteServer server;

  server.address = this->address;
  server.id = this->id;
  server.map_id = this->map_id;
  server.mode_id = this->mode_id;
  server.name = this->name;
  server.port = this->port;

  return server;
}

/* Sets the server IP address */
RemoteServer::Builder* RemoteServer::Builder::setAddress(QString address)
{
  this->address = address;
  return this;
}

/* Sets the unique identifier for the server */
RemoteServer::Builder* RemoteServer::Builder::setId(QString id)
{
  this->id = id;
  return this;
}

/* Sets the map identifier currently running on the server */
RemoteServer::Builder* RemoteServer::Builder::setMapId(Map map_id)
{
  this->map_id = map_id;
  return this;
}

/* Sets the mode identifier currently running on the server */
RemoteServer::Builder* RemoteServer::Builder::setModeId(Mode mode_id)
{
  this->mode_id = mode_id;
  return this;
}

/* Sets the readable name for the active server */
RemoteServer::Builder* RemoteServer::Builder::setName(QString name)
{
  this->name = name;
  return this;
}

/* Sets the server port number */
RemoteServer::Builder* RemoteServer::Builder::setPort(QString port)
{
  this->port = port;
  return this;
}
