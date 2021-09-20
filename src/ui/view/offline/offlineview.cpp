/**
 * @class OfflineView
 *
 * Top level widget that handles the offline skirmish flow screens and cycling through
 * them based on the current selection.
 */
#include "ui/view/offline/offlineview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
OfflineView::OfflineView(QWidget *parent) : QWidget(parent)
{
  QGridLayout* layout = new QGridLayout(this);
  layout->setMargin(0);
  layout->setRowStretch(1, 1);

  // Animated background
  AnimatedBackground* background = new AnimatedBackground(this);
  background->addBackground(":/image/bg-offline1.jpg");
  layout->addWidget(background, 0, 0, -1, -1);

  // Page header
  PageHeader* header = new PageHeader("Offline Skirmish", "Main Menu", this);
  connect(header, SIGNAL(selectBackButton()), this, SIGNAL(selectBackButton()));
  layout->addWidget(header, 0, 0);

  // Stack of views, one to be displayed at a time only
  QStackedLayout* view_layout = new QStackedLayout();

  // TODO: Place views here

  layout->addLayout(view_layout, 1, 0);
}
