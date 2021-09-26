/**
 * @class MultiplayerView
 *
 * Top level widget that handles the multiplayer flow screens and cycling through
 * them based on the current selection.
 */
#ifndef MULTIPLAYERVIEW_H
#define MULTIPLAYERVIEW_H

#include <QGridLayout>
#include <QStackedLayout>
#include <QWidget>

#include "ui/view/create/gamecreateview.h"
#include "ui/view/multiplayer/multiplayerjoinview.h"
#include "ui/view/multiplayer/multiplayermainview.h"
#include "ui/widget/animatedbackground.h"
#include "ui/widget/pageheader.h"

class MultiplayerView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  MultiplayerView(QWidget *parent = nullptr);

private:
  /* Create new game view */
  GameCreateView *view_create;

  /* Stack of all functional views in the body of the page */
  QStackedLayout *view_layout;

  /* Main view. Starting point of the multiplayer flow */
  MultiplayerMainView *view_main;

  /* Join existing game view */
  MultiplayerJoinView *view_join;

signals:
  /* Back button selected in view */
  void backClicked();

private slots:
  /* Back selected in the page. Cycle back through the views before exiting this view */
  void backToPreviousView();

  /* View the create new game flow */
  void viewCreate();

  /* View the join (search) for existing game flow */
  void viewJoin();

  /* View the main screen */
  void viewMain();
};

#endif // MULTIPLAYERVIEW_H
