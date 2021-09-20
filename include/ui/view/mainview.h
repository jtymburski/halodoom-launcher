/**
 * @class MainView
 *
 * Controls and renders a widget that is an animated background which will
 * both handle rotating backgrounds on a timer, shifting with a parallex and
 * custom overlays.
 */
#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGridLayout>
#include <QWidget>

#include "ui/widget/animatedbackground.h"
#include "ui/widget/menubutton.h"

class MainView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  MainView(QWidget *parent = nullptr);

private:
  /* Menu button font size in pixels */
  const static int BUTTON_FONT_SIZE_PX = 50;

signals:
  /* Exit option selected in view */
  void selectExit();

  /* Multiplayer option selected in view */
  void selectMultiplayer();

  /* Offline skirmish option selected in view */
  void selectOfflineSkirmish();
};

#endif // MAINVIEW_H
