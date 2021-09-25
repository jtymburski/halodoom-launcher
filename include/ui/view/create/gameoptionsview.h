/**
 * @class GameOptionsView
 *
 * Choose game options during the game create flow. Example options like bots, max number of
 * players, time limit, score, etc.
 */
#ifndef GAMEOPTIONSVIEW_H
#define GAMEOPTIONSVIEW_H

#include <QWidget>

class GameOptionsView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  GameOptionsView(QWidget *parent = nullptr);
};

#endif // GAMEOPTIONSVIEW_H
