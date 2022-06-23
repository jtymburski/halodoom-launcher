/**
 * @class GameSelectView
 *
 * Select game choice during the game create flow. This is any selection that can be created
 * with {@link GameSelection}.
 */
#include "ui/view/create/gameselectview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
GameSelectView::GameSelectView(QWidget *parent)
              : QWidget(parent),
                current_selection(Selection::Builder().build())
{
  layout = new QGridLayout(this);
  layout->setColumnStretch(0, 2);
  layout->setColumnStretch(2, 1);
  layout->setColumnStretch(3, 1);
  layout->setColumnStretch(4, 5);
  layout->setColumnStretch(5, 1);
  layout->setColumnStretch(6, 1);
  //layout->setRowStretch(0, 1);
  layout->setRowStretch(2, 5);
  layout->setRowStretch(5, 2);

  // UI : Left Column is handled by {@link createSelections(QVector<GameSelection>)}

  // UI : Right Column
  label_image = new QLabel(this);
  layout->addWidget(label_image,1, 3, 3, 3);

  TextView *label_description_header = new TextView("SUMMARY", QColor("#68c4ff"), 24*(parentWidget()->parentWidget()->parentWidget()->width()/1920.0),
                                                    QSize(0, 0), this);
  layout->addWidget(label_description_header, 4, 3);

  label_description = new TextView("Description", QColorConstants::White, 25*(parentWidget()->parentWidget()->parentWidget()->width()/1920.0), QSize(0, 0), this);
  label_description->setWordWrap(true);
  layout->addWidget(label_description, 5, 3,3,3,Qt::AlignTop);
}

/* ---- PRIVATE SLOT FUNCTIONS ---- */

/**
 * Set the current selection, mark that a selection has been made.
 * @param selection new game choice
 */
void GameSelectView::setSelection(const Selection &selection)
{
  current_selection = selection;
  emit selected();
}

/**
 * Update the active selection being displayed.
 * @param selection new game choice
 */
void GameSelectView::viewSelection(const Selection &selection)
{
  label_description->setText(selection.getDescription());
  label_image->setStyleSheet(
        "QLabel {"
          "border:0;"
          "border-image:url(" + selection.getImagePath() + ") 0 0 0 0 stretch stretch"
        "}");
}

/* ---- PROTECTED FUNCTIONS ---- */

/**
 * Creates the full list of all available selections in the UI.
 * @param title header name of the selections
 * @param selections list of selections. Must not be empty
 */
void GameSelectView::createSelections(const QString &title,
                                      const QList<Selection> &selections)
{
  this->selections = QVector<Selection>::fromList(selections);

  // UI
  layout->removeItem(layout_names);
  layout_names = new QVBoxLayout();
  layout_names->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

  TextView *label_header = new TextView(title, QColor("#68c4ff"), 34*(parentWidget()->parentWidget()->parentWidget()->width()/1920.0), QSize(0, 0), this);
  layout_names->addWidget(label_header);
  layout_names->addSpacerItem(new QSpacerItem(0, 20));

  for(auto const &selection : qAsConst(this->selections))
  {
    MenuButton *button_choice = new MenuButton(selection.getName(), 32*(parentWidget()->parentWidget()->parentWidget()->width()/1920.0));
    connect(button_choice, &MenuButton::clicked, this, [=]() { this->setSelection(selection); });
    connect(button_choice, &MenuButton::hovered, this, [=]() { this->viewSelection(selection); });
    layout_names->addWidget(button_choice);
  }

  layout_names->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_names, 2, 1);

  viewSelection(selections.first());
}

/* ---- PUBLIC FUNCTIONS ---- */

/**
 * Returns the last selection that was made by the user in the view.
 * @return selection choice
 */
Selection GameSelectView::getSelection() const
{
  return current_selection;
}
