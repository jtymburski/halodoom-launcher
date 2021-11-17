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
#include <QWidget>

#include "network/networkapi.h"
#include "ui/widget/menubutton.h"
#include "ui/widget/textview.h"

class MultiplayerJoinView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  MultiplayerJoinView(QWidget *parent = nullptr);

private:
  /* Network API interface */
  NetworkAPI *network_api;

private slots:
  /* Update the list of servers */
  void updateServers(const QVector<RemoteServer> &servers);
};

#endif // MULTIPLAYERJOINVIEW_H
