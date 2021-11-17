/**
 * @class MultiplayerGame
 *
 * Single, playable multiplayer game properties and configuration for the UI.
 */
#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include "model/remoteserver.h"
#include "ui/model/selection.h"

class MultiplayerGame
{
public:
  class Builder;

private:
  /* Private blank constructor, use {@link Builder} */
  MultiplayerGame() = default;

  /* Map UI properties */
  Selection map = Selection::Builder().build();

  /* Mode UI properties */
  Selection mode = Selection::Builder().build();

  /* Remote server configuration */
  RemoteServer server = RemoteServer::Builder().build();

public:
  /* Returns the map UI properties */
  Selection getMap() const;

  /* Returns the mode UI properties */
  Selection getMode() const;

  /* Returns the remote server configuration */
  RemoteServer getServer() const;

  /* Builder nested class for constructing the selection immutable object */
  class Builder
  {
  private:
    Selection map = Selection::Builder().build();
    Selection mode = Selection::Builder().build();
    RemoteServer server = RemoteServer::Builder().build();

  public:
    MultiplayerGame build();
    Builder* setMap(Selection map);
    Builder* setMode(Selection mode);
    Builder* setServer(RemoteServer server);
  };
};

#endif // MULTIPLAYERGAME_H
