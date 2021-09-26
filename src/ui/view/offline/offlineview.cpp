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
  QGridLayout *layout = new QGridLayout(this);
  layout->setMargin(0);
  layout->setRowStretch(1, 1);

  // Animated background
  AnimatedBackground *background = new AnimatedBackground(this);
  background->addBackground(":/image/background/offline1.jpg");
  layout->addWidget(background, 0, 0, -1, -1);

  // Page header
  PageHeader *header = new PageHeader("Offline Skirmish", "Main Menu", this);
  connect(header, SIGNAL(backClicked()), this, SLOT(backToPreviousView()));
  layout->addWidget(header, 0, 0);

  // Game create main view
  view_create = new GameCreateView(this);
  layout->addWidget(view_create, 1, 0);
}

/**
 * Back selected slot in the page. Cycle back through the views before exiting this view.
 */
void OfflineView::backToPreviousView()
{
  if(!view_create->backToPreviousView())
    emit backClicked();
}
