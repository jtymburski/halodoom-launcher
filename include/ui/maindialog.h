#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QGuiApplication>
#include <QScreen>
#include <QStackedLayout>

#include "game/gamecontroller.h"
#include "network/networkinfo.h"
#include "ui/view/mainview.h"
#include "ui/widget/animatedbackground.h"

class MainDialog : public QDialog
{
  Q_OBJECT

public:
  MainDialog(QWidget *parent = nullptr);
  ~MainDialog();

private:
  /* Game controller */
  GameController game_controller;

  /* Network info access implementation */
  NetworkInfo network_info;

  /* Resolution options */
  const static QSize RESOLUTION_LARGE;
  const static QSize RESOLUTION_SMALL;
};
#endif // MAINDIALOG_H
