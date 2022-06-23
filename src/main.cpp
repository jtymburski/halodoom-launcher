#include "ui/maindialog.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QFontDatabase::addApplicationFont(":/font/bahnschrift.ttf");

  MainDialog dialog;
  //dialog.setFixedSize(1280,720);
  dialog.show();

  return app.exec();
}
