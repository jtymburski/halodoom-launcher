/**
 * @class MultiplayerJoinView
 *
 * Join view during the multiplayer flow. Presents all available games that are available
 * to search and can be joined.
 */
#include "ui/view/multiplayer/multiplayerjoinview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
MultiplayerJoinView::MultiplayerJoinView(QWidget *parent) : QWidget(parent)
{
  QGridLayout *layout = new QGridLayout(this);
  layout->setColumnMinimumWidth(0, 100);
  layout->setColumnStretch(1, 2);
  layout->setColumnMinimumWidth(2, 50);
  layout->setColumnStretch(3, 1);
  layout->setColumnMinimumWidth(4, 100);
  layout->setRowMinimumHeight(0, 100);
  layout->setRowStretch(1, 1);
  layout->setRowStretch(3, 1);
  layout->setRowMinimumHeight(5, 100);

  // Table view
  QGridLayout *table_layout = new QGridLayout();
  table_layout->setHorizontalSpacing(40);
  table_layout->setVerticalSpacing(10);

  // Table headers
  TextView *header_server = new TextView("Server", QColorConstants::White, 28,
                                         QSize(15, 0), this);
  table_layout->addWidget(header_server, 0, 0);
  TextView *header_map = new TextView("Map", QColorConstants::White, 28,
                                      QSize(15, 0), this);
  table_layout->addWidget(header_map, 0, 1);
  TextView *header_mode = new TextView("Game Mode", QColorConstants::White, 28,
                                        QSize(15, 0), this);
  table_layout->addWidget(header_mode, 0, 2);
  TextView *header_count = new TextView("Player Count", QColorConstants::White, 28,
                                        QSize(15, 0), this);
  table_layout->addWidget(header_count, 0, 3);

  // Table rows
  for(int row = 1; row < 15; row++)
  {
    MenuButton *button_row = new MenuButton("", 24, this);
    button_row->setBackgroundFilled(true);
    table_layout->addWidget(button_row, row, 0, 1, 4);

    for(int col = 0; col < 4; col++)
    {
      TextView *cell = new TextView("-", QColorConstants::White, 24,
                                    QSize(15, 0), button_row);
      cell->setAttribute(Qt::WA_TransparentForMouseEvents, true);
      table_layout->addWidget(cell, row, col);
    }
  }
  layout->addLayout(table_layout, 1, 1, 4, 1);

  // Selected game details
  QLabel *label_game_image = new QLabel(this);
  label_game_image->setStyleSheet(
        "QLabel {"
          "border:0;"
          "border-image:url(:/image/map/rebellion.jpg) 0 0 0 0 stretch stretch"
        "}");
  layout->addWidget(label_game_image, 1, 3);

  TextView *label_game_title = new TextView("Rebellion SWAT", QColor("#68c4ff"), 34,
                                            QSize(0, 0), this);
  layout->addWidget(label_game_title, 2, 3);

  TextView *label_game_description = new TextView("Amidst the outskirts of the holy city, in the "
                                                  "hall of the ancestors, a great heresy brews..."
                                                  "\n\n"
                                                  "Aim for the head! Slayer with no shield, "
                                                  "radar, or ordinance.", QColorConstants::White,
                                                  20, QSize(0, 0), this);
  label_game_description->setWordWrap(true);
  layout->addWidget(label_game_description, 3, 3, Qt::AlignTop);

  // Join Button
  MenuButton *button_join = new MenuButton("Join →", 42, this);
  layout->addWidget(button_join, 4, 3, Qt::AlignBottom | Qt::AlignRight);
}
