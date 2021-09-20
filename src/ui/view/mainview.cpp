/**
 * @class MainView
 *
 * Controls and renders a widget that is an animated background which will
 * both handle rotating backgrounds on a timer, shifting with a parallex and
 * custom overlays.
 */
#include "ui/view/mainview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
MainView::MainView(QWidget *parent) : QWidget(parent)
{
  QGridLayout* layout = new QGridLayout(this);
  layout->setRowStretch(0, 1);
  layout->setColumnStretch(1, 1);
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

  // Buttons
  QVBoxLayout* button_layout = new QVBoxLayout();
  button_layout->setContentsMargins(175, 150, 150, 150);
  button_layout->setSpacing(15);

  MenuButton* multiplayer_button = new MenuButton("Multiplayer", BUTTON_FONT_SIZE_PX, this);
  connect(multiplayer_button, SIGNAL(clicked()), this, SIGNAL(selectMultiplayer()));
  button_layout->addWidget(multiplayer_button);

  MenuButton* offline_button = new MenuButton("Offline Skirmish", BUTTON_FONT_SIZE_PX, this);
  connect(offline_button, SIGNAL(clicked()), this, SIGNAL(selectOfflineSkirmish()));
  button_layout->addWidget(offline_button);

  MenuButton* exit_button = new MenuButton("Exit", BUTTON_FONT_SIZE_PX, this);
  connect(exit_button, SIGNAL(clicked()), this, SIGNAL(selectExit()));
  button_layout->addWidget(exit_button);

  layout->addLayout(button_layout, 1, 0);
}
