/**
 * @class GameModeView
 *
 * Select game mode during the game create flow. Example modes is like slayer, swat, etc.
 */
#ifndef GAMEMODEVIEW_H
#define GAMEMODEVIEW_H

#include "ui/model/database.h"
#include "ui/view/create/gameselectview.h"

class GameModeView : public GameSelectView
{
public:
  /* Constructor, with just the parent */
  GameModeView(QWidget *parent = nullptr);
};

#endif // GAMEMODEVIEW_H
