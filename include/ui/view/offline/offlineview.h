/**
 * @class OfflineView
 *
 * Top level widget that handles the offline skirmish flow screens and cycling through
 * them based on the current selection.
 */
#ifndef OFFLINEVIEW_H
#define OFFLINEVIEW_H

#include <QGridLayout>
#include <QWidget>

#include "game/gamecontroller.h"
#include "ui/view/create/gamecreateview.h"
#include "ui/widget/animatedbackground.h"
#include "ui/widget/pageheader.h"

class OfflineView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  OfflineView(GameController *controller, QWidget *parent = nullptr);

private:
  /* Create new game view */
  GameCreateView *view_create;

signals:
  /* Back button selected in view */
  void backClicked();

private slots:
  /* Back selected in the page. Cycle back through the views before exiting this view */
  void backToPreviousView();
};

#endif // OFFLINEVIEW_H
