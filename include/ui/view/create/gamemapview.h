/**
 * @class GameMapView
 *
 * Select game map during the game create flow. Example maps like warehouse, ghost ship, etc.
 */
#ifndef GAMEMAPVIEW_H
#define GAMEMAPVIEW_H

#include <QWidget>

class GameMapView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  GameMapView(QWidget *parent = nullptr);
};

#endif // GAMEMAPVIEW_H
