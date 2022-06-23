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
  buildLoadOuts();
}

/* Build all available maps and cache internally */
void Database::buildMaps()
{
    maps.insert(Map::LOCKUP, Selection::Builder()
                .setDescription("Lockup (2-8 players)\n\nThis laboratory is a prison.")
                ->setImagePath(":/image/map/lockup.jpg")
                ->setName("Lockup")
                ->setType(Map::LOCKUP)
                ->build());
    maps.insert(Map::WAREHOUSE, Selection::Builder()
                .setDescription("Warehouse (2-6 players)\n\nLethbridge Industrial once operated out of several small "
                                "facilities like this for the design and manufacture of their "
                                "experimental armor and weapons. Most of these sites were "
                                "decomissioned in favor of the raw storage space")
                ->setImagePath(":/image/map/warehouse.jpg")
                ->setName("Warehouse")
                ->setType(Map::WAREHOUSE)
                ->build());
    maps.insert(Map::SUBMERGED, Selection::Builder()
                 .setDescription("Submerged (2-8 players)\n\nBeneath the seas of Installation 02 lie a variety of mysterious "
                                 "Forerunner structures, echoes of memories long since past "
                                 "reverberate off of these monolithic walls, mingling with the "
                                 "ambience of deep")
                ->setImagePath(":/image/map/submerged.jpg")
                ->setName("Submerged")
                ->setType(Map::SUBMERGED)
                ->build());
    maps.insert(Map::REBELLION, Selection::Builder()
                .setDescription("Rebellion (4-10 players)\n\nAmidst the outskirts of the holy city, in the hall of the "
                                "ancestors, a great heresy brews...")
                ->setImagePath(":/image/map/rebellion.jpg")
                ->setName("Rebellion")
                ->setType(Map::REBELLION)
                ->build());
    maps.insert(Map::GHOSTSHIP, Selection::Builder()
                .setDescription("Ghostship (2-6 players)\n\nIn the emptiness of space, this fragment of the past floats "
                                "alone, silent, unnerving")
                ->setImagePath(":/image/map/ghostship.jpg")
                ->setName("Ghost Ship")
                ->setType(Map::GHOSTSHIP)
                ->build());
    maps.insert(Map::LIMINAL, Selection::Builder()
                .setDescription("Liminal (4-10 players)\n\nThe purpose of these Forerunner liminal spaces remain unknown."
                                "Humming deep in the underground of Installation 01, never revisited.")
                ->setImagePath(":/image/map/liminal.jpg")
                ->setName("Liminal")
                ->setType(Map::LIMINAL)
                ->build());
    maps.insert(Map::FLOOD_GULCH, Selection::Builder()
                .setDescription("Flood Gulch (4-16 players)\n\nThe former inhabitants of this installation are now one with "
                                "it's structures. Eradication protocols were activated as "
                                "intended, but clearly something went very wrong")
                ->setImagePath(":/image/map/floodgulch.jpg")
                ->setName("Flood Gulch")
                ->setType(Map::FLOOD_GULCH)
                ->build());
    maps.insert(Map::VERDANT, Selection::Builder()
                .setDescription("Verdant (2-8 players)\n\nAlthough Installation 01 was built with a barren simplicity, "
                                "the inner sanctum of 001 Empty Network is bathed in the emerald light"
                                "of the lush jungle sector.")
                ->setImagePath(":/image/map/verdant.jpg")
                ->setName("Verdant")
                ->setType(Map::VERDANT)
                ->build());
    maps.insert(Map::TERMINUS, Selection::Builder()
                .setDescription("Terminus (4-16 players)\n\nThe rail system that once connected the islands of Trigate "
                                "Now lay dormant in the absence of the cities inhabitants.")
                ->setImagePath(":/image/map/terminus.jpg")
                ->setName("Terminus")
                ->setType(Map::TERMINUS)
                ->build());
    maps.insert(Map::SCHISM, Selection::Builder()
                .setDescription("Schism (4-10 players)\n\nPerhaps there is more to the Great Journey than even the Prophets intended.")
                ->setImagePath(":/image/map/schism.jpg")
                ->setName("Schism")
                ->setType(Map::SCHISM)
                ->build());
    maps.insert(Map::THRESHOLD, Selection::Builder()
                .setDescription("Threshold (4-10 players)\n\nCertain forms are timeless.")
                ->setImagePath(":/image/map/threshold.jpg")
                ->setName("Threshold")
                ->setType(Map::THRESHOLD)
                ->build());
    maps.insert(Map::TRIGATE, Selection::Builder()
                .setDescription("Trigate (4-10 players)\n\nLethbridge Industrial, now known for it's technological advancement"
                                "Once had an affinity for the organic building materials of the natural world.")
                ->setImagePath(":/image/map/trigate.jpg")
                ->setName("Trigate")
                ->setType(Map::TRIGATE)
                ->build());
    maps.insert(Map::INFINITE, Selection::Builder()
                .setDescription("Infinity (6-16 players)\n\nSeveral of these structures exist on the surface of Installation 02"
                                "Its violent waters churn a somber song infinitely into the night.")
                ->setImagePath(":/image/map/infinity.jpg")
                ->setName("Infinity")
                ->setType(Map::INFINITE)
                ->build());
}

/* Build all available modes and cache internally */
void Database::buildModes()
{
  modes.insert(Mode::SLAYER, Selection::Builder()
              .setDescription("Slayer\n\nKill as many of your opponents as you can.")
              ->setImagePath(":/image/mode/slayer.jpg")
              ->setName("Slayer")
              ->setType(Mode::SLAYER)
              ->build());
  modes.insert(Mode::ODDBALL, Selection::Builder()
              .setDescription("Oddball\n\nHold the ball to win.")
              ->setImagePath(":/image/mode/oddball.jpg")
              ->setName("Oddball")
              ->setType(Mode::ODDBALL)
              ->build());
  modes.insert(Mode::KINGOFTHEHILL, Selection::Builder()
              .setDescription("King Of The Hill\n\nStay in the hill to win.")
              ->setImagePath(":/image/mode/koth.jpg")
              ->setName("King Of The Hill")
              ->setType(Mode::KINGOFTHEHILL)
              ->build());
  modes.insert(Mode::JUGGERNAUT, Selection::Builder()
              .setDescription("Juggernaut\n\nKill the Juggernaut.")
              ->setImagePath(":/image/mode/juggernaut.jpg")
              ->setName("Juggernaut")
              ->setType(Mode::JUGGERNAUT)
              ->build());
  modes.insert(Mode::INFECTION, Selection::Builder()
              .setDescription("Infection\n\nHumans against zombies.")
              ->setImagePath(":/image/mode/infection.jpg")
              ->setName("Infection")
              ->setType(Mode::INFECTION)
              ->build());
  modes.insert(Mode::SWAT, Selection::Builder()
              .setDescription("SWAT\n\nAim for the head. Slayer with no shield, radar, or ordinance.")
              ->setImagePath(":/image/mode/swat.jpg")
              ->setName("SWAT")
              ->setType(Mode::SWAT)
              ->build());
}


/* Build all available loadouts and cache internally */
void Database::buildLoadOuts()
{
  loadouts.insert(LoadOut::STANDARD, Selection::Builder()
              .setDescription("Standard\n\nStart with Assault Rifle, Magnum and Grenades. \nStandard weapons on map.")
              ->setImagePath(":/image/loadout/standard.jpg")
              ->setName("Standard")
              ->setType(LoadOut::STANDARD)
              ->build());
  loadouts.insert(LoadOut::HARDCORE, Selection::Builder()
              .setDescription("Hardcore\n\nStart with Battle Rifle, Magnum and a Frag Grenade. No radar.\nStandard weapons on map.")
              ->setImagePath(":/image/loadout/hardcore.jpg")
              ->setName("Hardcore")
              ->setType(LoadOut::HARDCORE)
              ->build());
  loadouts.insert(LoadOut::FIESTA, Selection::Builder()
              .setDescription("Fiesta\n\nRandomized weapon starts. \nNo weapons on map.")
              ->setImagePath(":/image/loadout/fiesta.jpg")
              ->setName("Fiesta")
              ->setType(LoadOut::FIESTA)
              ->build());
  loadouts.insert(LoadOut::SMALLARMS, Selection::Builder()
              .setDescription("Small Arms\n\nStart with Magnum and Plasma Pistol. \nNo weapons on map.")
              ->setImagePath(":/image/loadout/smallarms.jpg")
              ->setName("Small Arms")
              ->setType(LoadOut::SMALLARMS)
              ->build());
  loadouts.insert(LoadOut::SNIPERS, Selection::Builder()
              .setDescription("Snipers\n\nStart with Sniper Rifle and Beam Rifle. No radar. \nNo weapons on map.")
              ->setImagePath(":/image/loadout/snipers.jpg")
              ->setName("Snipers")
              ->setType(LoadOut::SNIPERS)
              ->build());
  loadouts.insert(LoadOut::HOTNHEAVY, Selection::Builder()
              .setDescription("Hot N' Heavy\n\nStart with Rocket Launcher, Fuel Rod Cannon and Firebomb Grenades. \nNo weapons on map.")
              ->setImagePath(":/image/loadout/heavy.jpg")
              ->setName("Hot N Heavy")
              ->setType(LoadOut::HOTNHEAVY)
              ->build());
  loadouts.insert(LoadOut::SWORDS, Selection::Builder()
              .setDescription("Swords\n\nStart with Energy Sword. \nNo weapons on map.")
              ->setImagePath(":/image/loadout/swords.jpg")
              ->setName("Swords")
              ->setType(LoadOut::SWORDS)
              ->build());
  loadouts.insert(LoadOut::SHOTTYSNIPERS, Selection::Builder()
              .setDescription("Shotty Snipers\n\nStart with Sniper Rifle and Shotgun. No radar. \nNo weapons on map.")
              ->setImagePath(":/image/loadout/ss.jpg")
              ->setName("Shotty Snipers")
              ->setType(LoadOut::SHOTTYSNIPERS)
              ->build());
  loadouts.insert(LoadOut::SLICENDICE, Selection::Builder()
              .setDescription("Slice N' Dice\n\nStart with Energy Sword or Chainsaw. \nNo weapons on map.")
              ->setImagePath(":/image/loadout/slice.jpg")
              ->setName("Slice N Dice")
              ->setType(LoadOut::SLICENDICE)
              ->build());
  loadouts.insert(LoadOut::UNSC, Selection::Builder()
              .setDescription("UNSC\n\nStart with Assault Rifle, Magnum and Frag Grenades. \nUNSC weapons on map.")
              ->setImagePath(":/image/loadout/unsc.jpg")
              ->setName("UNSC")
              ->setType(LoadOut::UNSC)
              ->build());
  loadouts.insert(LoadOut::COVENANT, Selection::Builder()
              .setDescription("Covenant\n\nStart with Plasma Rifle, Plasma Pistol and Plasma Grenades. \nCovenant weapons on map.")
              ->setImagePath(":/image/loadout/covenant.jpg")
              ->setName("Covenant")
              ->setType(LoadOut::COVENANT)
              ->build());
  loadouts.insert(LoadOut::BRUTE, Selection::Builder()
              .setDescription("Brute\n\nStart with Spiker Rifle, Mauler and Spike Grenades. \nBrute weapons on map.")
              ->setImagePath(":/image/loadout/brute.jpg")
              ->setName("Brute")
              ->setType(LoadOut::BRUTE)
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

/* Return a UI selection for a given loadout */
Selection Database::getLoadout(LoadOut loadout_id)
{
  return loadouts.find(loadout_id).value();
}

/* Return all available loadout UI selections */
QList<Selection> Database::getLoadouts()
{
  return loadouts.values();
}

/* Return all available mode UI selections */
QList<Selection> Database::getModes()
{
  return modes.values();
}
