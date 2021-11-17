/**
 * @class GameMapView
 *
 * Select game map during the game create flow. Example maps like warehouse, ghost ship, etc.
 */
#include "ui/view/create/gamemapview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
GameMapView::GameMapView(QWidget *parent) : GameSelectView(parent)
{
  Database ui_database;
  createSelections("Choose Map", ui_database.getMaps());
}
