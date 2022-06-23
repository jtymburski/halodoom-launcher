/**
 * @class GameLoadOutView
 *
 * Select game loadout during the game create flow.
 */
#ifndef GAMELOADOUTVIEW_H
#define GAMELOADOUTVIEW_H

#include "ui/model/database.h"
#include "ui/view/create/gameselectview.h"

class GameLoadOutView : public GameSelectView
{
public:
  /* Constructor, with just the parent */
  GameLoadOutView(QWidget *parent = nullptr);
};

#endif // GAMEMODEVIEW_H
