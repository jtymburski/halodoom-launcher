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
  label_bot_image = new QLabel(this);
  layout->addWidget(label_bot_image, 2, 1);

  TextView *label_description_header = new TextView("SUMMARY", QColor("#68c4ff"), 24,
                                                    QSize(0, 0), this);
  layout->addWidget(label_description_header, 3, 1);

  label_bot_description = new TextView("", QColorConstants::White, 20, QSize(0, 0), this);
  label_bot_description->setWordWrap(true);
  layout->addWidget(label_bot_description, 4, 1, 1, 4, Qt::AlignTop);

  TextView *label_add_header = new TextView("Add Bots", QColor("#68c4ff"), 34,
                                            QSize(0, 0), this);
  layout->addWidget(label_add_header, 1, 3);

  // Selectable list of bots
  available_bots = createAvailableBots();
  QVBoxLayout *layout_add_buttons = new QVBoxLayout();
  layout_add_buttons->addSpacerItem(
        new QSpacerItem(0, 25, QSizePolicy::Expanding, QSizePolicy::Fixed));

  for(auto const &bot : qAsConst(this->available_bots))
  {
    MenuButton *button_bot = new MenuButton(bot.getName(), 30, this);
    connect(button_bot, &MenuButton::clicked, this, [=]() { this->addBot(bot); });
    connect(button_bot, &MenuButton::hovered, this, [=]() { this->viewBot(bot); });
    layout_add_buttons->addWidget(button_bot);
  }
  viewBot(available_bots.first());

  layout_add_buttons->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_add_buttons, 2, 3);

  QVBoxLayout *layout_added_players = new QVBoxLayout();
  for(int i = 0; i < 8; i++)
  {
    MenuButton *row = new MenuButton("-", 30, this);
    row->setBackgroundFilled(true);
    connect(row, &MenuButton::clicked, this, [=]() { this->removeBot(i); });
    layout_added_players->addWidget(row);
    selected_bot_views.append(row);
  }
  layout_added_players->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_added_players, 1, 5, 4, 1);

  // Option Names (Left Column)
  QVBoxLayout *layout_option_names = new QVBoxLayout();

  TextView *label_player_count = new TextView("Max Players", QColorConstants::White, 30,
                                       QSize(25, 12), this);
  layout_option_names->addWidget(label_player_count);

  TextView *label_time_limit = new TextView("Time Limit", QColorConstants::White, 30,
                                            QSize(25, 12), this);
  layout_option_names->addWidget(label_time_limit);

  TextView *label_score_limit = new TextView("Score Limit", QColorConstants::White, 30,
                                             QSize(25, 12), this);
  layout_option_names->addWidget(label_score_limit);

  layout_option_names->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_option_names, 1, 7, 4, 1);

  // Option Interactive UI (Center Column)
  QVBoxLayout *layout_options = new QVBoxLayout();

  slider_player_count = new Slider(8, 1, 16, this);
  connect(slider_player_count, &Slider::valueChanged, this, &GameOptionsView::updatePlayerCount);
  layout_options->addWidget(slider_player_count);

  slider_time_limit = new Slider(20, 2, 120, this);
  connect(slider_time_limit, &Slider::valueChanged, this, &GameOptionsView::updateTimeLimit);
  layout_options->addWidget(slider_time_limit);

  slider_score_limit = new Slider(50, 1, 500, this);
  connect(slider_score_limit, &Slider::valueChanged, this, &GameOptionsView::updateScoreLimit);
  layout_options->addWidget(slider_score_limit);

  layout_options->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_options, 1, 9, 4, 1);

  // Option Text Details (Right Column)
  QVBoxLayout *layout_option_details = new QVBoxLayout();

  label_player_count_value = new TextView("8", QColorConstants::White, 22,
                                                    QSize(25, 16), this);
  layout_option_details->addWidget(label_player_count_value);

  label_time_limit_value = new TextView("20 min", QColorConstants::White, 22,
                                                  QSize(25, 16), this);
  layout_option_details->addWidget(label_time_limit_value);

  label_score_limit_value = new TextView("50", QColorConstants::White, 22,
                                                   QSize(25, 16), this);
  layout_option_details->addWidget(label_score_limit_value);

  layout_option_details->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_option_details, 1, 10, 4, 1);

  // Create Button
  QHBoxLayout *layout_create = new QHBoxLayout();
  layout_create->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  MenuButton* button_create = new MenuButton("Create →", 42, this);
  connect(button_create, &MenuButton::clicked, this, &GameOptionsView::configured);
  layout_create->addWidget(button_create);
  layout_create->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_create, 4, 8, 2, 3);
}

/* ---- PRIVATE FUNCTIONS ---- */

/* Creates the set of available bots */
QVector<GameSelection> GameOptionsView::createAvailableBots()
{
  return QVector<GameSelection> {
        GameSelection::Builder()
            .setDescription("Leader of the Code of Silence, favors heavy combat and vehicles")
            ->setImagePath(":/image/player/ramsus.jpg")
            ->setName("Ramsus")
            ->setType(Bot::RAMSUS)
            ->build(),
        GameSelection::Builder()
            .setDescription("Technician for the Code of Silence, favors stealth and cunning")
            ->setImagePath(":/image/player/avalon.jpg")
            ->setName("Avalon")
            ->setType(Bot::AVALON)
            ->build(),
        GameSelection::Builder()
            .setDescription("Infiltration specialist for the Code of Silence, she favors "
                            "small arms")
            ->setImagePath(":/image/player/nexiam.jpg")
            ->setName("Nexiam")
            ->setType(Bot::NEXIAM)
            ->build(),
        GameSelection::Builder()
            .setDescription("Sniper for the Code of Silence. Favors long range combat")
            ->setImagePath(":/image/player/uzziel.jpg")
            ->setName("Uzziel")
            ->setType(Bot::UZZIEL)
            ->build(),
        GameSelection::Builder()
            .setDescription("Samurai of the Code of Silence, favors Covenant weapons, with "
                            "a particular fondness of the Energy Sword")
            ->setImagePath(":/image/player/zetsui.jpg")
            ->setName("Zetsui")
            ->setType(Bot::ZETSUI)
            ->build()
  };
}

/* Update the selected bots list in the UI */
void GameOptionsView::updateSelectedBots()
{
  for(int i = 0; i < selected_bot_views.size(); i++)
  {
    if(i < selected_bots.size())
      selected_bot_views.at(i)->setText(selected_bots.at(i).getName());
    else
      selected_bot_views.at(i)->setText("-");
  }
}

/* ---- PRIVATE SLOT FUNCTIONS ---- */

/* Add the bot in the UI to the game configuration */
void GameOptionsView::addBot(const GameSelection &bot)
{
  if(selected_bots.size() < selected_bot_views.size())
  {
    selected_bots.append(bot);
    updateSelectedBots();
  }
}

/* Remove a bot from the game configuration */
void GameOptionsView::removeBot(int index)
{
  if(index >= 0 && index < selected_bots.size())
  {
    selected_bots.remove(index);
    updateSelectedBots();
  }
}

/* Updates the max player count option */
void GameOptionsView::updatePlayerCount(int player_count)
{
  label_player_count_value->setText(QString::number(player_count));
}

/* Updates the end game score limit (kills) */
void GameOptionsView::updateScoreLimit(int score_limit)
{
  label_score_limit_value->setText(QString::number(score_limit));
}

/* Updates the end game time limit, in minutes */
void GameOptionsView::updateTimeLimit(int time_limit)
{
  label_time_limit_value->setText(QString::number(time_limit) + " minutes");
}

/* View the selected bot in the UI */
void GameOptionsView::viewBot(const GameSelection &bot)
{
  label_bot_description->setText(bot.getDescription());
  label_bot_image->setStyleSheet(
        "QLabel {"
          "border:0;"
          "border-image:url(" + bot.getImagePath() + ") 0 0 0 0 stretch stretch"
        "}");
}

/* ---- PUBLIC FUNCTIONS ---- */

/* Returns the selected list of bots */
QVector<GameSelection> GameOptionsView::getBots() const
{
  return selected_bots;
}

/* Returns the player count maximum configuration */
int GameOptionsView::getPlayerCount() const
{
  return slider_player_count->value();
}

/* Returns the game score limit configuration, in total kills */
int GameOptionsView::getScoreLimit() const
{
  return slider_score_limit->value();
}

/* Returns the time limit configuration, in minutes */
int GameOptionsView::getTimeLimit() const
{
  return slider_time_limit->value();
}
