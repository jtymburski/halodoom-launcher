/**
 * @class GameModeView
 *
 * Select game mode during the game create flow. Example modes is like slayer, swat, etc.
 */
#include "ui/view/create/gamemodeview.h"

/**
 * Constructor, with just the parent.
 * @param parent top level owning widget, for garbage collection
 */
GameModeView::GameModeView(QWidget *parent) : GameSelectView(parent)
{
  createSelections("Choose Mode", QVector<GameSelection> {
        GameSelection::Builder()
            .setDescription("Kill as many of your opponents as you can. The player with the "
                            "most points wins.")
            ->setImagePath(":/image/mode/slayer.jpg")
            ->setName("Slayer")
            ->setType(Mode::SLAYER)
            ->build(),
        GameSelection::Builder()
            .setDescription("Aim for the head! Slayer with no shield, radar, or ordinance.")
            ->setImagePath(":/image/mode/swat.jpg")
            ->setName("SWAT")
            ->setType(Mode::SWAT)
            ->build(),
        GameSelection::Builder()
            .setDescription("Slice and dice your way to victory!")
            ->setImagePath(":/image/mode/swords.jpg")
            ->setName("Swords")
            ->setType(Mode::SWORDS)
            ->build(),
        GameSelection::Builder()
            .setDescription("Long and short range only, cut out the middleman.")
            ->setImagePath(":/image/mode/snipers.jpg")
            ->setName("Shotty Snipers")
            ->setType(Mode::SHOTTY_SHIPERS)
            ->build(),
        GameSelection::Builder()
            .setDescription("You never know what you'll get!")
            ->setImagePath(":/image/mode/fiesta.jpg")
            ->setName("Fiesta")
            ->setType(Mode::FIESTA)
            ->build()
  });
}
