/**
 * @class MultiplayerMainView
 *
 * First view during the multiplayer flow. Handles the initial create vs browse
 * selection.
 */
#ifndef MULTIPLAYERMAINVIEW_H
#define MULTIPLAYERMAINVIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QWidget>

#include "ui/widget/imagebutton.h"

class MultiplayerMainView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  MultiplayerMainView(QWidget *parent = nullptr);

signals:
  /* Create new game clicked in UI */
  void createClicked();

  /* Join (search) for existing game clicked in UI */
  void joinClicked();
};

#endif // MULTIPLAYERMAINVIEW_H
