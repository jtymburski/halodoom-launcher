
/**
 * @class GameLoadoutView
 *
 * Select game loadout during the game create flow.
 */
#include "ui/view/create/gameloadoutview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
GameLoadOutView::GameLoadOutView(QWidget *parent) : GameSelectView(parent)
{
  Database ui_database;
  createSelections("Choose Loadout", ui_database.getLoadouts());
}
