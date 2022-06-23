/**
 * @class MultiplayerJoinView
 *
 * Join view during the multiplayer flow. Presents all available games that are available
 * to search and can be joined.
 */
#ifndef MULTIPLAYERJOINVIEW_H
#define MULTIPLAYERJOINVIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QWidget>
#include <QColor>

#include "game/gamecontroller.h"
#include "network/networkapi.h"
#include "ui/model/database.h"
#include "ui/view/multiplayer/multiplayergame.h"
#include "ui/widget/menubutton.h"
#include "ui/widget/textview.h"

class MultiplayerJoinView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  MultiplayerJoinView(GameController *controller, QWidget *parent = nullptr);

private:
  /* Active list of all games that are available */
  QVector<MultiplayerGame> active_games;

  /* Game controller, business logic functionality */
  GameController *controller;

  /* Label dynamic widgets */
  TextView *label_game_description;
  QLabel *label_game_image;
  TextView *label_game_title;

  /* Network API interface */
  NetworkAPI *network_api;

  /* Selected game that is being previewed */
  MultiplayerGame selected_game = MultiplayerGame::Builder().build();

  /* UI database */
  Database ui_database;

  /* UI table view */
  QVector<QVector<TextView*>> view_table;

private:
  /* Update the server table view */
  void updateServerTableView();

private slots:
  /* Join the selected server */
  void joinServer();

  /* Sets the currently selected server */
  void selectServer(int row);

  /* Update the list of servers */
  void updateServers(const QVector<RemoteServer> &servers);
};

#endif // MULTIPLAYERJOINVIEW_H
