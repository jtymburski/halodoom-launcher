/**
 * @class GameOptionsView
 *
 * Choose game options during the game create flow. Example options like bots, max number of
 * players, time limit, score, etc.
 */
#include "ui/view/create/gameoptionsview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
GameOptionsView::GameOptionsView(QWidget *parent) : QWidget(parent)
{
  QGridLayout *layout = new QGridLayout(this);
  layout->setColumnStretch(0, 1);
  layout->setColumnStretch(1, 4);
  layout->setColumnStretch(2, 1);
  layout->setColumnStretch(3, 3);
  layout->setColumnStretch(4, 1);
  layout->setColumnStretch(5, 5);
  layout->setColumnStretch(6, 1);
  // Use text width for column 7
  layout->setColumnMinimumWidth(8, 10);
  layout->setColumnStretch(9, 2);
  layout->setColumnStretch(10, 2);
  layout->setRowStretch(0, 1);
  // Use text height for column 1
  layout->setRowStretch(2, 4);
  // Use text height for column 3
  layout->setRowStretch(4, 1);
  layout->setRowStretch(5, 1);

  // Bot preview and description
  QLabel *label_image = new QLabel(this);
  label_image->setStyleSheet(
        "QLabel {"
          "border:0;"
          "border-image:url(:/image/player/avalon.jpg) 0 0 0 0 stretch stretch"
        "}");
  layout->addWidget(label_image, 2, 1);

  TextView *label_description_header = new TextView("SUMMARY", QColor("#68c4ff"), 24,
                                                    QSize(0, 0), this);
  layout->addWidget(label_description_header, 3, 1);

  TextView *label_description = new TextView("Samurai of the Code of Silence, favors Covenant "
                                             "weapons, with a particular fondness to the Energy "
                                             "Sword",
                                             QColorConstants::White, 20, QSize(0, 0), this);
  label_description->setWordWrap(true);
  layout->addWidget(label_description, 4, 1, 1, 4, Qt::AlignTop);

  TextView *label_add_header = new TextView("Add Bots", QColor("#68c4ff"), 34,
                                            QSize(0, 0), this);
  layout->addWidget(label_add_header, 1, 3);

  // Selectable list of bots
  QVBoxLayout *layout_add_buttons = new QVBoxLayout();
  layout_add_buttons->addSpacerItem(
        new QSpacerItem(0, 25, QSizePolicy::Expanding, QSizePolicy::Fixed));

  MenuButton *button1 = new MenuButton("Ramsus", 30, this);
  layout_add_buttons->addWidget(button1);
  MenuButton *button2 = new MenuButton("Avalon", 30, this);
  layout_add_buttons->addWidget(button2);
  MenuButton *button3 = new MenuButton("Nexiam", 30, this);
  layout_add_buttons->addWidget(button3);
  MenuButton *button4 = new MenuButton("Uzziel", 30, this);
  layout_add_buttons->addWidget(button4);
  MenuButton *button5 = new MenuButton("Zetsui", 30, this);
  layout_add_buttons->addWidget(button5);

  layout_add_buttons->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_add_buttons, 2, 3);

  QVBoxLayout *layout_added_players = new QVBoxLayout();
  for(int i = 0; i < 9; i++)
  {
    MenuButton *row = new MenuButton("-", 30);
    row->setBackgroundFilled(true);
    layout_added_players->addWidget(row);
  }
  layout_added_players->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_added_players, 1, 5, 4, 1);

  // Option Names (Left Column)
  QVBoxLayout *layout_option_names = new QVBoxLayout();

  TextView *label_name1 = new TextView("Max Players", QColorConstants::White, 30,
                                       QSize(25, 12), this);
  layout_option_names->addWidget(label_name1);

  TextView *label_name2 = new TextView("Time Limit", QColorConstants::White, 30,
                                       QSize(25, 12), this);
  layout_option_names->addWidget(label_name2);

  TextView *label_name3 = new TextView("Score Limit", QColorConstants::White, 30,
                                       QSize(25, 12), this);
  layout_option_names->addWidget(label_name3);

  layout_option_names->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_option_names, 1, 7, 4, 1);

  // Option Interactive UI (Center Column)
  QVBoxLayout *layout_options = new QVBoxLayout();

  Slider *slider1 = new Slider(8, 1, 16, this);
  layout_options->addWidget(slider1);

  Slider *slider2 = new Slider(20, 1, 120, this);
  layout_options->addWidget(slider2);

  Slider *slider3 = new Slider(50, 1, 500, this);
  layout_options->addWidget(slider3);

  layout_options->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_options, 1, 9, 4, 1);

  // Option Text Details (Right Column)
  QVBoxLayout *layout_option_details = new QVBoxLayout();

  TextView *label_desc1 = new TextView("8", QColorConstants::White, 22, QSize(25, 16), this);
  layout_option_details->addWidget(label_desc1);

  TextView *label_desc2 = new TextView("20 min", QColorConstants::White, 22, QSize(25, 16), this);
  layout_option_details->addWidget(label_desc2);

  TextView *label_desc3 = new TextView("50", QColorConstants::White, 22, QSize(25, 16), this);
  layout_option_details->addWidget(label_desc3);

  layout_option_details->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_option_details, 1, 10, 4, 1);
}
