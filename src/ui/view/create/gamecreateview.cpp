/**
 * @class GameCreateView
 *
 * Top level create widget for the process of creating any game, offline or online, with the
 * options that are available.
 */
#include "ui/view/create/gamecreateview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
GameCreateView::GameCreateView(QWidget *parent) : QWidget(parent)
{
  view_layout = new QStackedLayout(this);

  view_map = new GameMapView(this);
  view_layout->addWidget(view_map);

  view_mode = new GameModeView(this);
  view_layout->addWidget(view_mode);

  view_options = new GameOptionsView(this);
  view_layout->addWidget(view_options);

  viewMap();
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
