#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QInputDialog>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>

#include "game/gamecontroller.h"
#include "network/networkinfo.h"

class MainDialog : public QDialog
{
  Q_OBJECT

public:
  MainDialog(QWidget *parent = nullptr);
  ~MainDialog();

private:
  /* Last or current IP address the client is using for the remote server */
  QString client_server_addr = "127.0.0.1";

  /* Game controller */
  GameController game_controller;

  /* Network info access implementation */
  NetworkInfo network_info;

  /* Server widgets */
  QLabel* server_addr_label;
  QPushButton* server_button;

  /* Background image resource path */
  const static QString kBACKGROUND_PATH;

private slots:
  /* Client button click */
  void onClientClick();

  /* Launch button click */
  void onLaunchClick();

  /* Server button click */
  void onServerClick();
};
#endif // MAINDIALOG_H
