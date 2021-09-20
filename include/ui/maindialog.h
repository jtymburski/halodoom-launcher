#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QGuiApplication>
#include <QScreen>
#include <QStackedLayout>

#include "game/gamecontroller.h"
#include "network/networkinfo.h"
#include "ui/view/mainview.h"
#include "ui/view/multiplayer/multiplayerview.h"
#include "ui/view/offline/offlineview.h"

class MainDialog : public QDialog
{
  Q_OBJECT

public:
  MainDialog(QWidget *parent = nullptr);

private:
  /* Game controller */
  GameController game_controller;

  /* Network info access implementation */
  NetworkInfo network_info;

  /* Stack of all views, only one shown at a time */
  QStackedLayout* view_layout;

  /* Main (home) view */
  MainView* view_main;

  /* Multiplayer view flow */
  MultiplayerView* view_multiplayer;

  /* Offline skirmish view flow */
  OfflineView* view_offline;

  /* Resolution options */
  const static QSize RESOLUTION_LARGE;
  const static QSize RESOLUTION_SMALL;

private slots:
  /* Close and exit the dialog */
  void exit();

  /* View the main screen */
  void viewMain();

  /* View the multiplayer flow */
  void viewMultiplayer();

  /* View the offline skirmish flow */
  void viewOfflineSkirmish();
};
#endif // MAINDIALOG_H
