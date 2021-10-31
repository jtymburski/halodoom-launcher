/**
 * @class GameOptionsView
 *
 * Choose game options during the game create flow. Example options like bots, max number of
 * players, time limit, score, etc.
 */
#ifndef GAMEOPTIONSVIEW_H
#define GAMEOPTIONSVIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "model/gametypes.h"
#include "ui/view/create/gameselection.h"
#include "ui/widget/menubutton.h"
#include "ui/widget/slider.h"
#include "ui/widget/textview.h"

class GameOptionsView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  GameOptionsView(QWidget *parent = nullptr);

private:
  /* List of all available bots */
  QVector<GameSelection> available_bots;

  /* Active bot information */
  TextView *label_bot_description;
  QLabel *label_bot_image;

  /* Slider labels */
  TextView *label_player_count_value;
  TextView *label_score_limit_value;
  TextView *label_time_limit_value;

  /* List of selected bots and the UI views */
  QVector<GameSelection> selected_bots;
  QVector<QPushButton*> selected_bot_views;

  /* Sliders */
  Slider *slider_player_count;
  Slider *slider_score_limit;
  Slider *slider_time_limit;

signals:
  /* Finished setting up the game options */
  void configured();

private:
  /* Creates the set of available bots */
  QVector<GameSelection> createAvailableBots();

  /* Update the selected bots list in the UI */
  void updateSelectedBots();

private slots:
  /* Add the bot in the UI to the game configuration */
  void addBot(const GameSelection &bot);

  /* Remove a bot from the game configuration */
  void removeBot(int index);

  /* Updates the max player count option */
  void updatePlayerCount(int player_count);

  /* Updates the end game score limit (kills) */
  void updateScoreLimit(int score_limit);

  /* Updates the end game time limit, in minutes */
  void updateTimeLimit(int time_limit);

  /* View the selected bot in the UI */
  void viewBot(const GameSelection &bot);

public:
  /* Returns the selected list of bots */
  QVector<GameSelection> getBots() const;

  /* Returns the player count maximum configuration */
  int getPlayerCount() const;

  /* Returns the game score limit configuration, in total kills */
  int getScoreLimit() const;

  /* Returns the time limit configuration, in minutes */
  int getTimeLimit() const;
};

#endif // GAMEOPTIONSVIEW_H
