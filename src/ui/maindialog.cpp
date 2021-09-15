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

  QGridLayout* layout = new QGridLayout(this);
  layout->setRowStretch(0, 1);
  layout->setColumnStretch(0, 1);
  layout->setMargin(0);

  // Animated background
  AnimatedBackground* background = new AnimatedBackground(this);
  background->addBackground(":/image/bg-main1.jpg");
  background->addBackground(":/image/bg-main2.jpg");
  background->addBackground(":/image/bg-main3.jpg");
  background->addBackground(":/image/bg-main4.jpg");
  background->addBackground(":/image/bg-main5.jpg");
  background->addOverlay(":/image/halodoom.png");
  layout->addWidget(background, 0, 0, -1, -1);

  QVBoxLayout* button_layout = new QVBoxLayout();
  button_layout->setMargin(35);

  // Server label
  server_addr_label = new QLabel("", this);
  server_addr_label->setAlignment(Qt::AlignCenter);
  server_addr_label->setStyleSheet("QLabel { font-size: 15px; font-weight: bold; color : green; }");
  button_layout->addWidget(server_addr_label);

  // Launch button configuration
  server_button = new QPushButton("Host Server", this);
  server_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
  connect(server_button, SIGNAL(clicked()), this, SLOT(onServerClick()));
  button_layout->addWidget(server_button);

  QPushButton* client_button = new QPushButton("Connect to Server", this);
  client_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
  connect(client_button, SIGNAL(clicked()), this, SLOT(onClientClick()));
  button_layout->addWidget(client_button);

  QPushButton* launch_button = new QPushButton("Launch Game", this);
  launch_button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
  connect(launch_button, SIGNAL(clicked()), this, SLOT(onLaunchClick()));
  button_layout->addWidget(launch_button);

  layout->addLayout(button_layout, 1, 1);
}

MainDialog::~MainDialog()
{
}

/**
 * Client button click.
 */
void MainDialog::onClientClick()
{
  bool ok;
  QString addr = QInputDialog::getText(this, tr("Server Address"),
                                       tr("Running server IP address?"), QLineEdit::Normal,
                                       client_server_addr, &ok,
                                       Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
  bool valid_addr = network_info.isValidAddress(addr);
  if(ok && !addr.isEmpty() && valid_addr)
  {
    client_server_addr = addr;

    try
    {
      game_controller.startClient(addr);
    }
    catch (const std::exception& e)
    {
      QMessageBox::warning(this, tr("Failed To Start"), tr(e.what()));
    }
  }
  else if(!valid_addr)
  {
    QMessageBox::warning(this, tr("Bad Address"),
                         tr("'%1' is an invalid server address").arg(addr));
  }
}

/**
 * Launch button click in the dialog. Expected to start the application.
 */
void MainDialog::onLaunchClick()
{
  // Start the game
  bool started = false;
  try
  {
    game_controller.start();
    started = true;
  }
  catch (const std::exception& e)
  {
    QMessageBox::warning(this, tr("Failed To Start"), tr(e.what()));
  }

  // Delay closure of the launcher as long as there is no attached server running
  if(started && !game_controller.isServerRunning())
  {
    // Delay closure of the app till game start
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(close()));
    timer->start(5000);
  }
}

/**
 * Server button click.
 */
void MainDialog::onServerClick()
{
  // TODO: Swap to use process slots for both updating the status text and state mgmt
  if(game_controller.isServerRunning())
  {
    game_controller.stopServer();
    server_addr_label->setText(QString());
    server_button->setText("Host Server");
  }
  else
  {
    QString local_address = network_info.localAddress();
    qInfo() << "[INFO] Starting server at address:" << local_address;

    // Start the server
    bool started = false;
    try
    {
      game_controller.startServer();
      started = true;
    }
    catch (const std::exception& e)
    {
      QMessageBox::warning(this, tr("Failed To Start"), tr(e.what()));
    }

    // Check the status
    if(started)
    {
      server_addr_label->setText(local_address);
      server_button->setText("Stop Server");
    }
  }
}
