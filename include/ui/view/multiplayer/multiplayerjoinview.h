/**
 * @class MultiplayerJoinView
 *
 * Join view during the multiplayer flow. Presents all available games that are available
 * to search and can be joined.
 */
#ifndef MULTIPLAYERJOINVIEW_H
#define MULTIPLAYERJOINVIEW_H

#include <QWidget>

class MultiplayerJoinView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  MultiplayerJoinView(QWidget *parent = nullptr);
};

#endif // MULTIPLAYERJOINVIEW_H
