#include "ui/maindialog.h"

/* Constant Implementation - see header file for descriptions */
const QSize MainDialog::RESOLUTION_LARGE = QSize(1920, 1080);
const QSize MainDialog::RESOLUTION_SMALL = QSize(1280, 720);

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
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

  view_layout = new QStackedLayout(this);

  view_main = new MainView(this);
  connect(view_main, SIGNAL(selectExit()), this, SLOT(exit()));
  connect(view_main, SIGNAL(selectMultiplayer()), this, SLOT(viewMultiplayer()));
  connect(view_main, SIGNAL(selectOfflineSkirmish()), this, SLOT(viewOfflineSkirmish()));
  view_layout->addWidget(view_main);

  view_multiplayer = new MultiplayerView(&game_controller, this);
  connect(view_multiplayer, SIGNAL(backClicked()), this, SLOT(viewMain()));
  view_layout->addWidget(view_multiplayer);

  view_offline = new OfflineView(&game_controller, this);
  connect(view_offline, SIGNAL(backClicked()), this, SLOT(viewMain()));
  view_layout->addWidget(view_offline);
}

/**
 * Close and exit the dialog.
 */
void MainDialog::exit()
{
  QCoreApplication::exit();
}

/**
 * View the main screen widget.
 */
void MainDialog::viewMain()
{
  view_layout->setCurrentWidget(view_main);
}

/**
 * View the multiplayer flow widget.
 */
void MainDialog::viewMultiplayer()
{
  view_layout->setCurrentWidget(view_multiplayer);
}

/**
 * View the offline skirmish flow widget.
 */
void MainDialog::viewOfflineSkirmish()
{
  view_layout->setCurrentWidget(view_offline);
}
