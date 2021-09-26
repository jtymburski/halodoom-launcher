/**
 * @class GameMapView
 *
 * Select game map during the game create flow. Example maps like warehouse, ghost ship, etc.
 */
#ifndef GAMEMAPVIEW_H
#define GAMEMAPVIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>

#include "ui/view/create/gameselection.h"
#include "ui/widget/menubutton.h"

class GameMapView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  GameMapView(QWidget *parent = nullptr);

private:
  /* UI elements for the currently displayed map */
  QLabel *label_description;
  QLabel *label_image;

  /* List of all configured map selection options */
  QVector<GameSelection> maps;

signals:
  /* A map has been selected by the user */
  void mapSelected();

private slots:
  /* Update the current map selection being displayed */
  void updateSelection(const GameSelection &selection);
};

#endif // GAMEMAPVIEW_H
