/**
 * @class GameMapView
 *
 * Select game map during the game create flow. Example maps like warehouse, ghost ship, etc.
 */
#include "ui/view/create/gamemapview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
GameMapView::GameMapView(QWidget *parent) : QWidget(parent)
{
  // Pre-loaded maps
  maps.append(GameSelection::Builder()
                .setDescription("Lethbridge Industrial once operated out of several small "
                                "facilities like this for the design and manufacture of their "
                                "experimental armor and weaponry. Most of these sites were "
                                "decomissioned in favor of having the raw storage space")
                ->setImagePath(":/image/map/warehouse.jpg")
                ->setName("Warehouse")
                ->build());
  maps.append(GameSelection::Builder()
                .setDescription("Beneath the seas of Installation 02 lie a variety of mysterious "
                                "Forerunner structures, echoes of memories long since past "
                                "reverberate off of these monolithic walls, mingling with the "
                                "ambience of deep")
                ->setImagePath(":/image/map/submerged.jpg")
                ->setName("Submerged")
                ->build());
  maps.append(GameSelection::Builder()
                .setDescription("Amidst the outskirts of the holy city, in the hall of the "
                                "ancestors, a great heresy brews...")
                ->setImagePath(":/image/map/rebellion.jpg")
                ->setName("Rebellion")
                ->build());
  maps.append(GameSelection::Builder()
                .setDescription("The former inhabitants of this installation are now one with "
                                "it's structures. Eradication protocols were activated as "
                                "intended, but clearly something went very wrong")
                ->setImagePath(":/image/map/floodgulch.jpg")
                ->setName("Flood Gulch")
                ->build());
  maps.append(GameSelection::Builder()
                .setDescription("In the emptiness of space, this fragment of the past floats "
                                "alone, silent, unnerving")
                ->setImagePath(":/image/map/ghostship.jpg")
                ->setName("Ghost Ship")
                ->build());

  // UI
  QGridLayout *layout = new QGridLayout(this);
  layout->setColumnStretch(0, 2);
  layout->setColumnStretch(2, 1);
  layout->setColumnStretch(3, 1);
  layout->setColumnStretch(4, 5);
  layout->setColumnStretch(5, 1);
  layout->setColumnStretch(6, 1);
  layout->setRowStretch(0, 1);
  layout->setRowStretch(2, 5);
  layout->setRowStretch(5, 2);

  // UI : Left Column
  QVBoxLayout *layout_names = new QVBoxLayout();
  layout_names->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

  QLabel *label_header = new QLabel("Choose Map", this);
  label_header->setStyleSheet(
        "QLabel {"
          "color:#68c4ff;"
          "font-family:bahnschrift;"
          "font-size:34px;"
          "QFont::bold"
        "}");
  layout_names->addWidget(label_header);
  layout_names->addSpacerItem(new QSpacerItem(0, 20));

  for(auto const &map : qAsConst(maps))
  {
    MenuButton *button_map = new MenuButton(map.getName(), 30);
    connect(button_map, &MenuButton::clicked, this, &GameMapView::mapSelected);
    connect(button_map, &MenuButton::hovered, this, [=]() { this->updateSelection(map); });
    layout_names->addWidget(button_map);
  }

  layout_names->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
  layout->addLayout(layout_names, 2, 1);

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

  updateSelection(maps.first());
}

/**
 * Update the current map selection being displayed.
 * @param selection new map properties
 */
void GameMapView::updateSelection(const GameSelection &selection)
{
  label_description->setText(selection.getDescription());
  label_image->setStyleSheet(
        "QLabel {"
          "border:0;"
          "border-image:url(" + selection.getImagePath() + ") 0 0 0 0 stretch stretch"
        "}");
}
