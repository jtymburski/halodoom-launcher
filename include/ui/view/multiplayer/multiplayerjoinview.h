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

#include "ui/widget/menubutton.h"
#include "ui/widget/textview.h"

class MultiplayerJoinView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  MultiplayerJoinView(QWidget *parent = nullptr);
};

#endif // MULTIPLAYERJOINVIEW_H
