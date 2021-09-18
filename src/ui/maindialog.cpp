#include "ui/maindialog.h"

/* Constant Implementation - see header file for descriptions */
const QSize MainDialog::RESOLUTION_LARGE = QSize(1920, 1080);
const QSize MainDialog::RESOLUTION_SMALL = QSize(1280, 720);

MainDialog::MainDialog(QWidget *parent)
  : QDialog(parent)
{
  // Only the close button should be enabled
  setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );

  // Fix the window size to the background
  QScreen* primary_screen = QGuiApplication::primaryScreen();
  if(primary_screen->geometry().width() > RESOLUTION_LARGE.width())
    setFixedSize(RESOLUTION_LARGE);
  else
    setFixedSize(RESOLUTION_SMALL);

  QStackedLayout* layout = new QStackedLayout(this);

  MainView* main_view = new MainView(this);
  layout->addWidget(main_view);
}

MainDialog::~MainDialog()
{
}
