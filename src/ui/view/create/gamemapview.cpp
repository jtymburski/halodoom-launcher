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
GameMapView::GameMapView(QWidget *parent) : GameSelectView(parent)
{
  createSelections("Choose Map", QVector<GameSelection> {
        GameSelection::Builder()
            .setDescription("Lethbridge Industrial once operated out of several small "
                            "facilities like this for the design and manufacture of their "
                            "experimental armor and weaponry. Most of these sites were "
                            "decomissioned in favor of having the raw storage space")
            ->setImagePath(":/image/map/warehouse.jpg")
            ->setName("Warehouse")
            ->build(),
        GameSelection::Builder()
            .setDescription("Beneath the seas of Installation 02 lie a variety of mysterious "
                            "Forerunner structures, echoes of memories long since past "
                            "reverberate off of these monolithic walls, mingling with the "
                            "ambience of deep")
            ->setImagePath(":/image/map/submerged.jpg")
            ->setName("Submerged")
            ->build(),
        GameSelection::Builder()
            .setDescription("Amidst the outskirts of the holy city, in the hall of the "
                            "ancestors, a great heresy brews...")
            ->setImagePath(":/image/map/rebellion.jpg")
            ->setName("Rebellion")
            ->build(),
        GameSelection::Builder()
            .setDescription("The former inhabitants of this installation are now one with "
                            "it's structures. Eradication protocols were activated as "
                            "intended, but clearly something went very wrong")
            ->setImagePath(":/image/map/floodgulch.jpg")
            ->setName("Flood Gulch")
            ->build(),
        GameSelection::Builder()
            .setDescription("In the emptiness of space, this fragment of the past floats "
                            "alone, silent, unnerving")
            ->setImagePath(":/image/map/ghostship.jpg")
            ->setName("Ghost Ship")
            ->build()
  });
}
