/**
 * @class MultiplayerView
 *
 * Top level widget that handles the multiplayer flow screens and cycling through
 * them based on the current selection.
 */
#include "ui/view/multiplayer/multiplayerview.h"

/**
 * Constructor, with just the parent.
 * @param controller game business logic encapsulation
 * @param parent top level owning widget, for garbage collection
 */
MultiplayerView::MultiplayerView(GameController *controller, QWidget *parent) : QWidget(parent)
{
  QGridLayout* layout = new QGridLayout(this);
  layout->setMargin(0);
  layout->setRowStretch(1, 1);

  // Animated background
  AnimatedBackground* background = new AnimatedBackground(this);
  background->addBackground(":/image/background/multi1.jpg");
  layout->addWidget(background, 0, 0, -1, -1);

  // Page header
  PageHeader* header = new PageHeader("Multiplayer", "Main Menu", this);
  connect(header, SIGNAL(backClicked()), this, SLOT(backToPreviousView()));
  layout->addWidget(header, 0, 0);

  // Stack of views, one to be displayed at a time only
  view_layout = new QStackedLayout();

  view_create = new GameCreateView(controller, this);
  view_layout->addWidget(view_create);

  view_join = new MultiplayerJoinView(this);
  view_layout->addWidget(view_join);

  view_main = new MultiplayerMainView(this);
  connect(view_main, SIGNAL(createClicked()), this, SLOT(viewCreate()));
  connect(view_main, SIGNAL(joinClicked()), this, SLOT(viewJoin()));
  view_layout->addWidget(view_main);

  layout->addLayout(view_layout, 1, 0);
  viewMain();
}

/**
 * Back selected slot in the page. Cycle back through the views before exiting this view.
 */
void MultiplayerView::backToPreviousView()
{
  if(view_layout->currentWidget() == view_create)
  {
    if(!view_create->backToPreviousView())
      viewMain();
  }
  else if(view_layout->currentWidget() == view_join)
  {
    viewMain();
  }
  else
  {
    emit backClicked();
    viewMain();
  }
}

/**
 * View the create new game flow widget slot.
 */
void MultiplayerView::viewCreate()
{
  view_layout->setCurrentWidget(view_create);
}

/**
 * View the join (search) for existing game flow widget slot.
 */
void MultiplayerView::viewJoin()
{
  view_layout->setCurrentWidget(view_join);
}

/**
 * View the main screen widget slot.
 */
void MultiplayerView::viewMain()
{
  view_layout->setCurrentWidget(view_main);
}
