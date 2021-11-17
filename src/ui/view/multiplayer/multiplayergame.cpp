/**
 * @class MultiplayerGame
 *
 * Single, playable multiplayer game properties and configuration for the UI.
 */
#include "ui/view/multiplayer/multiplayergame.h"

/* Returns the map UI properties */
Selection MultiplayerGame::getMap() const
{
  return map;
}

/* Returns the mode UI properties */
Selection MultiplayerGame::getMode() const
{
  return mode;
}

/* Returns the remote server configuration */
RemoteServer MultiplayerGame::getServer() const
{
  return server;
}

/**
 * Build the {@link MultiplayerGame} object from the configured builder.
 * @return built object
 */
MultiplayerGame MultiplayerGame::Builder::build()
{
  MultiplayerGame game;

  game.map = this->map;
  game.mode = this->mode;
  game.server = this->server;

  return game;
}

/* Sets the map UI properties */
MultiplayerGame::Builder* MultiplayerGame::Builder::setMap(Selection map)
{
  this->map = map;
  return this;
}

/* Sets the mode UI properties */
MultiplayerGame::Builder* MultiplayerGame::Builder::setMode(Selection mode)
{
  this->mode = mode;
  return this;
}

/* Sets the remote server configuration */
MultiplayerGame::Builder* MultiplayerGame::Builder::setServer(RemoteServer server)
{
  this->server = server;
  return this;
}
