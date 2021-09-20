/**
 * @class MultiplayerView
 *
 * Top level widget that handles the multiplayer flow screens and cycling through
 * them based on the current selection.
 */
#ifndef MULTIPLAYERVIEW_H
#define MULTIPLAYERVIEW_H

#include <QGridLayout>
#include <QStackedLayout>
#include <QWidget>

#include "ui/widget/animatedbackground.h"
#include "ui/widget/pageheader.h"

class MultiplayerView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  MultiplayerView(QWidget *parent = nullptr);

signals:
  /* Back button selected in view */
  void selectBackButton();
};

#endif // MULTIPLAYERVIEW_H
