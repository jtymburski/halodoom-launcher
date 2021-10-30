/**
 * @class GameCreateView
 *
 * Top level create widget for the process of creating any game, offline or online, with the
 * options that are available.
 */
#ifndef GAMECREATEVIEW_H
#define GAMECREATEVIEW_H

#include <QStackedLayout>
#include <QWidget>

#include "ui/view/create/gamemapview.h"
#include "ui/view/create/gamemodeview.h"
#include "ui/view/create/gameoptionsview.h"

class GameCreateView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  GameCreateView(QWidget *parent = nullptr);

private:
  /* Stack of all functional views in the body of the page */
  QStackedLayout *view_layout;

  /* Select game map view */
  GameMapView *view_map;

  /* Select game mode view */
  GameModeView *view_mode;

  /* Select game options view */
  GameOptionsView *view_options;

private slots:
  /* Create the game */
  void create();

  /* View the select game map flow */
  void viewMap();

  /* View the select game mode flow */
  void viewMode();

  /* View the select game options flow */
  void viewOptions();

public:
  /* Back requested in the views. Cycle back through the views available in the correct order */
  bool backToPreviousView();
};

#endif // GAMECREATEVIEW_H
