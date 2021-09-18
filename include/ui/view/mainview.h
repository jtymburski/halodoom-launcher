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
};

#endif // MAINVIEW_H
