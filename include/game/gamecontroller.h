/**
 * @class GameController
 *
 * Central controller for handling all game related business logic including
 * starting and stopping the remote processes. This should be used directly by
 * the UI.
 */
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QProcess>

#include "file/filereader.h"
#include "file/jsonargumentparser.h"
#include "game/config/maclaunchconfig.h"
#include "game/config/winlaunchconfig.h"
#include "game/argumenttranslator.h"
#include "game/config/launchconfig.h"

class GameController
{
public:
  /* Destructor function */
  ~GameController();

private:
  /* Argument translation handler */
  ArgumentTranslator argument_translator;

  /* Launch configuration for all run modes */
  LaunchConfig* launch_config = nullptr;

  /* Internal process, for last launched local server */
  QProcess *server_process = nullptr;

  /* Configuration file properties */
  const static QString CONFIG_CLIENT_OBJECT;
  const static QString CONFIG_FILE_NAME;
  const static QString CONFIG_SERVER_OBJECT;

private:
  /* Delete the currently loaded configuration */
  void deleteLaunchConfig();

  /* Start a game process, detached */
  void startGameProcess(const QList<Argument> &arguments);

  /* Start a server process, attached to the client */
  void startServerProcess(const QList<Argument> &arguments);

public:
  /* Checks if the local server process is running and attached to this controller */
  bool isServerRunning() const;

  /* Explicitly instructs the controller to load the config into memory */
  void loadConfig(bool reload = false);

  /* Execute and start a multiplayer client */
  void startClient(QString address);
  void startClient(QString address, QString port);

  /* Execute and start a local multiplayer server */
  void startServer();
  /* Execute and start the game, in normal start-up mode */
  void start();

  /* Execute and start a local multiplayer server and a client connected to that server */
  void startServerAndClient(const Map &map, const Mode &mode, const LoadOut &loadout, const QVector<Bot> &bots,
                            const int max_player_count = 8, const int score_limit = 0,
                            const int time_limit = 0, const int time_score_limit = 0,
                            const int teamgame = 2);

  /* Stop a running local multiplayer server, if it exists */
  void stopServer();
};

#endif // GAMECONTROLLER_H
