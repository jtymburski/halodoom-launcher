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
GameSelectView::GameSelectView(QWidget *parent) : QWidget(parent)
{
  layout = new QGridLayout(this);
  layout->setColumnStretch(0, 2);
  layout->setColumnStretch(2, 1);
  layout->setColumnStretch(3, 1);
  layout->setColumnStretch(4, 5);
  layout->setColumnStretch(5, 1);
  layout->setColumnStretch(6, 1);
  layout->setRowStretch(0, 1);
  layout->setRowStretch(2, 5);
  layout->setRowStretch(5, 2);

  // UI : Left Column is handled by {@link createSelections(QVector<GameSelection>)}

  // UI : Right Column
  label_image = new QLabel(this);
  layout->addWidget(label_image, 1, 3, 3, 3);

  QLabel *label_description_header = new QLabel("SUMMARY", this);
  label_description_header->setStyleSheet(
        "QLabel {"
          "color:#68c4ff;"
          "font-family:bahnschrift;"
          "font-size:18px;"
          "QFont::bold"
        "}");
  layout->addWidget(label_description_header, 4, 4);

  label_description = new QLabel(this);
  label_description->setWordWrap(true);
  label_description->setStyleSheet(
        "QLabel {"
          "color:white;"
          "font-family:bahnschrift;"
          "font-size:16px"
        "}");
  layout->addWidget(label_description, 5, 4, Qt::AlignTop);
}

/**
 * Update the current selection being displayed.
 * @param selection new map properties
 */
void GameSelectView::viewSelection(const GameSelection &selection)
{
  label_description->setText(selection.getDescription());
  label_image->setStyleSheet(
        "QLabel {"
          "border:0;"
          "border-image:url(" + selection.getImagePath() + ") 0 0 0 0 stretch stretch"
        "}");
}

/**
 * Creates the full list of all available selections in the UI.
 * @param title header name of the selections
 * @param selections list of selections. Must not be empty
 */
void GameSelectView::createSelections(const QString &title,
                                      const QVector<GameSelection> &selections)
{
  this->selections = selections;

  // UI
  layout->removeItem(layout_names);
  layout_names = new QVBoxLayout();
  layout_names->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

  QLabel *label_header = new QLabel(title, this);
  label_header->setStyleSheet(
        "QLabel {"
          "color:#68c4ff;"
          "font-family:bahnschrift;"
          "font-size:34px;"
          "QFont::bold"
        "}");
  layout_names->addWidget(label_header);
  layout_names->addSpacerItem(new QSpacerItem(0, 20));

  for(auto const &selection : qAsConst(this->selections))
  {
    MenuButton *button_map = new MenuButton(selection.getName(), 30);
    connect(button_map, &MenuButton::clicked, this, &GameSelectView::selected);
    connect(button_map, &MenuButton::hovered, this, [=]() { this->viewSelection(selection); });
    layout_names->addWidget(button_map);
  }

  layout_names->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_names, 2, 1);

  viewSelection(selections.first());
}
