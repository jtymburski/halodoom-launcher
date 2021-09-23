/**
 * @class OfflineView
 *
 * Top level widget that handles the offline skirmish flow screens and cycling through
 * them based on the current selection.
 */
#ifndef OFFLINEVIEW_H
#define OFFLINEVIEW_H

#include <QGridLayout>
#include <QStackedLayout>
#include <QWidget>

#include "ui/widget/animatedbackground.h"
#include "ui/widget/pageheader.h"

class OfflineView : public QWidget
{
  Q_OBJECT

public:
  /* Constructor, with just the parent */
  OfflineView(QWidget *parent = nullptr);

signals:
  /* Back button selected in view */
  void backClicked();
};

#endif // OFFLINEVIEW_H
