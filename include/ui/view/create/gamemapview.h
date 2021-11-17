/**
 * @class GameMapView
 *
 * Select game map during the game create flow. Example maps like warehouse, ghost ship, etc.
 */
#ifndef GAMEMAPVIEW_H
#define GAMEMAPVIEW_H

#include "ui/model/database.h"
#include "ui/view/create/gameselectview.h"

class GameMapView : public GameSelectView
{
public:
  /* Constructor, with just the parent */
  GameMapView(QWidget *parent = nullptr);
};

#endif // GAMEMAPVIEW_H
