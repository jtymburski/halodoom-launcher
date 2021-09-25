/**
 * @class GameModeView
 *
 * Select game mode during the game create flow. Example modes is like slayer, swat, etc.
 */
#ifndef GAMEMODEVIEW_H
#define GAMEMODEVIEW_H

#include <QWidget>

class GameModeView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  GameModeView(QWidget *parent = nullptr);
};

#endif // GAMEMODEVIEW_H
