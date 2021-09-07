/**
 * @class GameController
 *
 * Central controller for handling all game related business logic including
 * starting and stopping the remote processes. This should be used directly by
 * the UI.
 */
#include "game/gamecontroller.h"

/* Configuration file properties */
const QString GameController::CONFIG_CLIENT_OBJECT = QStringLiteral("clientArguments");
const QString GameController::CONFIG_FILE_NAME = QStringLiteral("config.json");
const QString GameController::CONFIG_SERVER_OBJECT = QStringLiteral("serverArguments");

/**
 * Destructor function
 */
GameController::~GameController()
{
  deleteLaunchConfig();
  stopServer();
}

/**
 * Delete the currently loaded configuration. This will erase all custom settings stored
 * in memory and require that {@link #loadConfig(bool)} is called again.
 */
void GameController::deleteLaunchConfig()
{
  if(launch_config != nullptr)
  {
    delete launch_config;
    launch_config = nullptr;
  }
}

/**
 * Starts a detached game process. This will try to load the Zandronum launcher in play mode
 * disconnected from launcher.
 * @param arguments custom arguments for starting the process
 */
void GameController::startGameProcess(const QList<Argument> &arguments)
{
  QStringList argument_string_list = argument_translator.toStringList(arguments);

  if(!QProcess::startDetached(launch_config->getZandronumBinaryFilepath(), argument_string_list))
    throw std::runtime_error("Game process failed to detach and start");
}

/**
 * Start a connected server process, for running a local Zandronum server.
 * @param arguments custom arguments for starting the process
 */
void GameController::startServerProcess(const QList<Argument> &arguments)
{
  QStringList argument_string_list = argument_translator.toStringList(arguments);

  stopServer();
  server_process = new QProcess();
  server_process->start(launch_config->getZandronumBinaryFilepath(), argument_string_list);
}

/* ---- PUBLIC FUNCTIONS ---- */

/**
 * Checks if the local server process is running and attached to this controller.
 * @return TRUE if its running, FALSE otherwise
 */
bool GameController::isServerRunning() const
{
  return server_process != nullptr && server_process->state() != QProcess::NotRunning;
}

/**
 * Load the {@link LaunchConfig} into memory. This will encapsulate all loading including
 * custom overrides from disk. This loaded config will be used for all start*() calls.
 * @param reload TRUE to force a reload and delete existing config. Default is FALSE
 */
void GameController::loadConfig(bool reload)
{
  if(launch_config == nullptr || reload)
  {
    deleteLaunchConfig();

    // Load in the correct config, based on the OS
#ifdef _WIN32
    launch_config = new WinLaunchConfig();
#elif __APPLE__
    launch_config = new MacLaunchConfig();
#endif

    // Add any custom configuration
    QJsonDocument config_json = FileReader::readFileToJson(
          launch_config->getBaseExecutableDirectory() + CONFIG_FILE_NAME);
    launch_config->insertClientArguments(
          JsonArgumentParser::parseArguments(config_json, CONFIG_CLIENT_OBJECT));
    launch_config->insertServerArguments(
          JsonArgumentParser::parseArguments(config_json, CONFIG_SERVER_OBJECT));
  }
}

/**
 * Execute and start the game, in normal start-up mode.
 * @throws std::invalid_parameter if the launch config is misconfigured
 */
void GameController::start()
{
  loadConfig();
  startGameProcess(launch_config->getBasicArguments());
}

/**
 * Execute and start a multiplayer client.
 * @throws std::invalid_parameter if the launch config is misconfigured
 */
void GameController::startClient(QString address)
{
  loadConfig();
  launch_config->setServerAddress(address);
  startGameProcess(launch_config->getClientArguments());
}

/**
 * Execute and start a local multiplayer server.
 * @throws std::invalid_parameter if the launch config is misconfigured
 */
void GameController::startServer()
{
  loadConfig();
  startServerProcess(launch_config->getServerArguments());
}

/**
 * Stop a running local multiplayer server, if it exists.
 */
void GameController::stopServer()
{
  if(server_process != nullptr)
  {
    server_process->kill();
    delete server_process;
    server_process = nullptr;
  }
}
