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
MultiplayerJoinView::MultiplayerJoinView(GameController *controller, QWidget *parent)
                   : QWidget(parent)
{
  this->controller = controller;

  QGridLayout *layout = new QGridLayout(this);
  layout->setColumnStretch(0, 2);
  layout->setColumnStretch(1, 12);
  layout->setColumnStretch(2, 1);
  layout->setColumnStretch(3, 6);
  layout->setColumnStretch(4, 1);
  layout->setRowStretch(0, 1);
  layout->setRowStretch(1, 4);
  layout->setRowStretch(3, 4);
  layout->setRowStretch(5, 1);

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
  TextView *header_mode = new TextView("Mode", QColorConstants::White, 28,
                                        QSize(15, 0), this);
  table_layout->addWidget(header_mode, 0, 2);
  TextView *header_count = new TextView("Players", QColorConstants::White, 28,
                                        QSize(15, 0), this);
  table_layout->addWidget(header_count, 0, 3);

  // Table rows
  for(int row = 1; row < 12; row++)
  {
    MenuButton *button_row = new MenuButton("", 20, this);
    button_row->setBackgroundFilled(true);
    connect(button_row, &MenuButton::clicked, this, [=]() { this->selectServer(row - 1); });
    table_layout->addWidget(button_row, row, 0, 1, 4);

    QVector<TextView*> view_table_row;
    for(int col = 0; col < 4; col++)
    {
      TextView *cell = new TextView("-", QColorConstants::White, 20,
                                    QSize(15, 0), button_row);
      cell->setAttribute(Qt::WA_TransparentForMouseEvents, true);
      table_layout->addWidget(cell, row, col);
      view_table_row.append(cell);
    }
    view_table.append(view_table_row);
  }
  table_layout->setRowStretch(12, 1);
  layout->addLayout(table_layout, 1, 1, 4, 1);

  // Selected game details
  label_game_image = new QLabel(this);
  label_game_image->setStyleSheet(
        "QLabel {"
          "border:0;"
          "border-image:url() 0 0 0 0 stretch stretch"
        "}");
  layout->addWidget(label_game_image, 1, 3);

  label_game_title = new TextView("", QColor("#68c4ff"), 34,
                                  QSize(0, 0), this);
  layout->addWidget(label_game_title, 2, 3);

  label_game_description = new TextView("", QColorConstants::White,
                                        20, QSize(0, 0), this);
  label_game_description->setWordWrap(true);
  layout->addWidget(label_game_description, 3, 3, Qt::AlignTop);

  // Join Button
  MenuButton *button_join = new MenuButton("Join →", 42, this);
  connect(button_join, &MenuButton::clicked, this, &MultiplayerJoinView::joinServer);
  layout->addWidget(button_join, 4, 3, Qt::AlignBottom | Qt::AlignRight);

  // Network API server fetch
  network_api = new NetworkAPI(this);
  network_api->getConfig();
  connect(network_api, &NetworkAPI::serversReceived, this, &MultiplayerJoinView::updateServers);
}

/* Update the server table view */
void MultiplayerJoinView::updateServerTableView()
{
  for(int row = 0; row < view_table.size(); row++)
  {
    for(int col = 0; col < view_table.at(row).size(); col++)
    {
      TextView *cell = view_table.at(row).at(col);

      if(row < active_games.size())
      {
        const MultiplayerGame &game = active_games.at(row);
        switch(col)
        {
          case 0:
            cell->setText(game.getServer().getName());
            break;
          case 1:
            cell->setText(game.getMap().getName());
            break;
          case 2:
            cell->setText(game.getMode().getName());
            break;
          default:
            cell->setText("-");
        }
      }
      else
      {
        cell->setText("-");
      }
    }
  }
}

/* Join the selected server */
void MultiplayerJoinView::joinServer()
{
  QString server_addr = selected_game.getServer().getAddress();
  QString server_port = selected_game.getServer().getPort();
  if(!server_addr.isEmpty() && !server_port.isEmpty())
    controller->startClient(server_addr, server_port);
}

/* Sets the currently selected server */
void MultiplayerJoinView::selectServer(int row)
{
  // Cache the current selected game
  if(row >= 0 && row < active_games.size())
    selected_game = active_games.at(row);
  else
    selected_game = MultiplayerGame::Builder().build();

  // Update the UI
  label_game_description->setText(selected_game.getMap().getDescription() + "\n\n" +
                                  selected_game.getMode().getDescription());
  label_game_image->setStyleSheet(
        "QLabel {"
          "border:0;"
          "border-image:url(" + selected_game.getMap().getImagePath() + ") 0 0 0 0 stretch stretch"
        "}");
  label_game_title->setText(selected_game.getMap().getName() + " " +
                            selected_game.getMode().getName());
}

/* Update the list of servers */
void MultiplayerJoinView::updateServers(const QVector<RemoteServer> &servers)
{
  active_games.clear();

  for (const RemoteServer &server : servers)
  {
    active_games.append(MultiplayerGame::Builder()
                        .setMap(ui_database.getMap(server.getMapId()))
                        ->setMode(ui_database.getMode(server.getModeId()))
                        ->setServer(server)
                        ->build());
  }

  updateServerTableView();
  selectServer(0);
}
