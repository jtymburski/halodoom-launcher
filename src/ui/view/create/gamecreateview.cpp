/**
 * @class GameCreateView
 *
 * Top level create widget for the process of creating any game, offline or online, with the
 * options that are available.
 */
#include "ui/view/create/gamecreateview.h"
#include <QDebug>

/**
 * Constructor, with just the parent.
 * @param controller game business logic encapsulation
 * @param parent top level owning widget, for garbage collection
 */
GameCreateView::GameCreateView(GameController *controller, QWidget *parent) : QWidget(parent)
{
  this->controller = controller;

  view_layout = new QStackedLayout(this);

  view_map = new GameMapView(this);
  connect(view_map, &GameMapView::selected, this, &GameCreateView::viewMode);
  view_layout->addWidget(view_map);

  view_mode = new GameModeView(this);
  connect(view_mode, &GameMapView::selected, this, &GameCreateView::viewOptions);
  view_layout->addWidget(view_mode);

  view_options = new GameOptionsView(this);
  connect(view_options, &GameOptionsView::configured, this, &GameCreateView::create);
  view_layout->addWidget(view_options);

  viewMap();
}

/* ---- PRIVATE SLOT FUNCTIONS ---- */

/**
 * Create the game.
 */
void GameCreateView::create()
{
  const GameSelection map = view_map->getSelection();
  const GameSelection mode = view_mode->getSelection();

  const QVector<GameSelection> bots = view_options->getBots();
  QVector<Bot> bot_types;
  for(int bot_index = 0; bot_index < bots.size(); bot_index++)
    bot_types.append((Bot) bots.at(bot_index).getType());

  controller->startServerAndClient((Map) map.getType(), (Mode) mode.getType(), bot_types,
                                   view_options->getPlayerCount(), view_options->getScoreLimit(),
                                   view_options->getTimeLimit());
}

/**
 * View the select game map flow.
 */
void GameCreateView::viewMap()
{
  view_layout->setCurrentWidget(view_map);
}

/**
 * View the select game mode flow.
 */
void GameCreateView::viewMode()
{
  view_layout->setCurrentWidget(view_mode);
}

/**
 * View the select game options flow.
 */
void GameCreateView::viewOptions()
{
  view_layout->setCurrentWidget(view_options);
}

/* ---- PUBLIC FUNCTIONS ---- */

/**
 * Back requested. Cycle back through the views available in the correct order. It will return
 * if a view change occurred.
 * @return TRUE if there was a view change. FALSE if there was no view change (at the first view)
 */
bool GameCreateView::backToPreviousView()
{
  if (view_layout->currentWidget() == view_options)
  {
    viewMode();
    return true;
  }
  else if (view_layout->currentWidget() == view_mode)
  {
    viewMap();
    return true;
  }
  else if (view_layout->currentWidget() == view_map)
  {
    return false;
  }

  throw std::domain_error("Unsupported view index=" + std::to_string(view_layout->currentIndex())
                          + " for back operation");
}
