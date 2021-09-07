#ifndef LAUNCHCONFIG_H
#define LAUNCHCONFIG_H

#include <QList>
#include <QMap>
#include <QString>

#include "file/filereader.h"
#include "model/argument.h"

class LaunchConfig
{
public:
  /* Destructor function of the implementation */
  virtual ~LaunchConfig();

private:
  /* Custom arguments */
  QMap<QString, Argument> arguments_client;
  QMap<QString, Argument> arguments_server;

  /* Server network address, for connecting as a client */
  QString server_address;

  /* Server connection limit (# of clients that can connect when hosting) */
  uint server_connection_limit = DEFAULT_CONNECTION_LIMIT;

  /* Default config settings */
  const static uint DEFAULT_CONNECTION_LIMIT = 4;
  const static QString DEFAULT_DOOM_FILENAME;
  const static QString DEFAULT_INI_FILENAME;
  const static QString DEFAULT_PK3_FILENAME;

  /* Parameter names for the config */
  const static QString PARAM_CONFIG_INI;
  const static QString PARAM_CONNECTION_LIMIT;
  const static QString PARAM_BASE_WAD;
  const static QString PARAM_MOD_PK3;
  const static QString PARAM_SERVER_ADDR;

private:
  /* Returns the base mapping of arguments, common for all game types */
  QMap<QString, Argument> getArgumentsMap(const QMap<QString, Argument> &extra_arguments) const;

  /* Returns the file reference to the doom WAD implementation */
  QString getDoomBinaryFilepath() const;

  /* Returns the file reference to the compiled mod (pk3) */
  QString getModBinaryFilepath() const;

  /* Returns the file reference to the mod configuration (ini) */
  QString getModConfigFilepath() const;

  /* Returns the server IPv4 address for connecting as a client */
  QString getServerAddress() const;

  /* Returns the server connection limits for clients when hosting */
  uint getServerConnectionLimit() const;

  /* Returns if the doom binary path is a valid file */
  bool isDoomBinaryValid() const;

  /* Returns if the mod binary path is a valid file */
  bool isModBinaryValid() const;

  /* Returns if the mod configuration path is a valid file */
  bool isModConfigValid() const;

  /* Returns if the server IPv4 address for connecting as a client is set */
  bool isServerAddressSet() const;

  /* Returns if the server connection limit for clients is set */
  bool isServerConnectionLimitSet() const;

  /* Returns if the zandronum path is a valid file */
  bool isZandronumBinaryValid() const;

  /* Validates the arguments in the config is set or will throw an exception */
  void validateArgumentsOrThrow() const;
  void validateClientArgumentsOrThrow() const;
  void validateServerArgumentsOrThrow() const;

public:
  /* Returns the base executable directory */
  virtual QString getBaseExecutableDirectory() const = 0;

  /* Returns a list of all arguments to start a basic game, straight to the menu */
  QList<Argument> getBasicArguments() const;

  /* Returns a list of all arguments to start a client game */
  QList<Argument> getClientArguments() const;

  /* Returns a list of all arguments to start a server */
  QList<Argument> getServerArguments() const;

  /* Returns the file reference to the zandronum binary */
  virtual QString getZandronumBinaryFilepath() const = 0;

  /* Insert a client argument to be included when the full list is generated */
  void insertClientArgument(const Argument &argument);
  void insertClientArguments(const QList<Argument> &arguments);

  /* Insert a server argument to be included when the full list is generated */
  void insertServerArgument(const Argument &argument);
  void insertServerArguments(const QList<Argument> &arguments);

  /* Sets the server IPv4 address for connecting as a client */
  void setServerAddress(QString address);

  /* Sets the server connection limits for clients when hosting */
  void setServerConnectionLimit(uint limit);
};

#endif // LAUNCHCONFIG_H
