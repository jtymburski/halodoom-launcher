/**
 * @class GameSelectView
 *
 * Select game choice during the game create flow. This is any selection that can be created
 * with {@link GameSelection}.
 */
#ifndef GAMESELECTVIEW_H
#define GAMESELECTVIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>

#include "ui/view/create/gameselection.h"
#include "ui/widget/menubutton.h"
#include "ui/widget/textview.h"

class GameSelectView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  GameSelectView(QWidget *parent = nullptr);

private:
  /* Last selected game choice */
  GameSelection current_selection;

  /* UI elements for the currently displayed selection */
  QLabel *label_description;
  QLabel *label_image;
  QGridLayout *layout;
  QVBoxLayout *layout_names;

  /* List of all configured selection options */
  QVector<GameSelection> selections;

signals:
  /* A selection has been made */
  void selected();

private slots:
  /* Set the current selection, mark that a selection has been made */
  void setSelection(const GameSelection &selection);

  /* Change the active selection being displayed */
  void viewSelection(const GameSelection &selection);

protected:
  /* Creates the full list of all available selections in the UI */
  void createSelections(const QString &title, const QVector<GameSelection> &selections);

public:
  /* Returns the last selection that was made */
  GameSelection getSelection() const;
};

#endif // GAMESELECTVIEW_H
