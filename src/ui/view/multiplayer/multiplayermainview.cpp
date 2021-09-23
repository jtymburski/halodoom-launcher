/**
 * @class MultiplayerMainView
 *
 * First view during the multiplayer flow. Handles the initial create vs browse
 * selection.
 */
#include "ui/view/multiplayer/multiplayermainview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
MultiplayerMainView::MultiplayerMainView(QWidget *parent) : QWidget(parent)
{
  // Create a grid where all columns are equal width and the middle row (#1) is 3:1 when scaling
  QGridLayout *layout = new QGridLayout(this);
  layout->setColumnStretch(0, 1);
  layout->setColumnStretch(1, 1);
  layout->setColumnStretch(2, 1);
  layout->setColumnStretch(3, 1);
  layout->setColumnStretch(4, 1);
  layout->setRowStretch(0, 1);
  layout->setRowStretch(1, 3);
  layout->setRowStretch(2, 1);

  // Create new multiplayer game option
  ImageButton *create_button = new ImageButton("Create New Game",
                                               ":/image/multiplayer/create.jpg",
                                               ":/image/multiplayer/create-hover.jpg",
                                               this);
  connect(create_button, SIGNAL(clicked()), this, SIGNAL(createClicked()));
  layout->addWidget(create_button, 1, 1);

  // Join existing multiplayer game option
  ImageButton *join_button = new ImageButton("Search For Game",
                                             ":/image/multiplayer/join.jpg",
                                             ":/image/multiplayer/join-hover.jpg",
                                             this);
  connect(join_button, SIGNAL(clicked()), this, SIGNAL(joinClicked()));
  layout->addWidget(join_button, 1, 3);
}
