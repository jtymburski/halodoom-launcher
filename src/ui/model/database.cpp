/**
 * @class Database
 *
 * User interface database of commonly accessed and re-used components.
 */
#include "ui/model/database.h"

/* Constructor */
Database::Database()
{
  buildMaps();
  buildModes();
}

/* Build all available maps and cache internally */
void Database::buildMaps()
{
  maps.insert(Map::WAREHOUSE, Selection::Builder()
              .setDescription("Lethbridge Industrial once operated out of several small "
                              "facilities like this for the design and manufacture of their "
                              "experimental armor and weaponry. Most of these sites were "
                              "decomissioned in favor of having the raw storage space")
              ->setImagePath(":/image/map/warehouse.jpg")
              ->setName("Warehouse")
              ->setType(Map::WAREHOUSE)
              ->build());
  maps.insert(Map::SUBMERGED, Selection::Builder()
              .setDescription("Beneath the seas of Installation 02 lie a variety of mysterious "
                              "Forerunner structures, echoes of memories long since past "
                              "reverberate off of these monolithic walls, mingling with the "
                              "ambience of deep")
              ->setImagePath(":/image/map/submerged.jpg")
              ->setName("Submerged")
              ->setType(Map::SUBMERGED)
              ->build());
  maps.insert(Map::REBELLION, Selection::Builder()
              .setDescription("Amidst the outskirts of the holy city, in the hall of the "
                              "ancestors, a great heresy brews...")
              ->setImagePath(":/image/map/rebellion.jpg")
              ->setName("Rebellion")
              ->setType(Map::REBELLION)
              ->build());
  maps.insert(Map::FLOOD_GULCH, Selection::Builder()
              .setDescription("The former inhabitants of this installation are now one with "
                              "it's structures. Eradication protocols were activated as "
                              "intended, but clearly something went very wrong")
              ->setImagePath(":/image/map/floodgulch.jpg")
              ->setName("Flood Gulch")
              ->setType(Map::FLOOD_GULCH)
              ->build());
  maps.insert(Map::GHOST_SHIP, Selection::Builder()
              .setDescription("In the emptiness of space, this fragment of the past floats "
                              "alone, silent, unnerving")
              ->setImagePath(":/image/map/ghostship.jpg")
              ->setName("Ghost Ship")
              ->setType(Map::GHOST_SHIP)
              ->build());
}

/* Build all available modes and cache internally */
void Database::buildModes()
{
  modes.insert(Mode::SLAYER, Selection::Builder()
              .setDescription("Kill as many of your opponents as you can. The player with the "
                              "most points wins.")
              ->setImagePath(":/image/mode/slayer.jpg")
              ->setName("Slayer")
              ->setType(Mode::SLAYER)
              ->build());
  modes.insert(Mode::SWAT, Selection::Builder()
              .setDescription("Aim for the head! Slayer with no shield, radar, or ordinance.")
              ->setImagePath(":/image/mode/swat.jpg")
              ->setName("SWAT")
              ->setType(Mode::SWAT)
              ->build());
  modes.insert(Mode::SWORDS, Selection::Builder()
              .setDescription("Slice and dice your way to victory!")
              ->setImagePath(":/image/mode/swords.jpg")
              ->setName("Swords")
              ->setType(Mode::SWORDS)
              ->build());
  modes.insert(Mode::SHOTTY_SHIPERS, Selection::Builder()
              .setDescription("Long and short range only, cut out the middleman.")
              ->setImagePath(":/image/mode/snipers.jpg")
              ->setName("Shotty Snipers")
              ->setType(Mode::SHOTTY_SHIPERS)
              ->build());
  modes.insert(Mode::FIESTA, Selection::Builder()
              .setDescription("You never know what you'll get!")
              ->setImagePath(":/image/mode/fiesta.jpg")
              ->setName("Fiesta")
              ->setType(Mode::FIESTA)
              ->build());
}

/* Return a UI selection for a given map */
Selection Database::getMap(Map map_id)
{
  return maps.find(map_id).value();
}

/* Return all available map UI selections */
QList<Selection> Database::getMaps()
{
  return maps.values();
}

/* Return a UI selection for a given mode */
Selection Database::getMode(Mode mode_id)
{
  return modes.find(mode_id).value();
}

/* Return all available mode UI selections */
QList<Selection> Database::getModes()
{
  return modes.values();
}
