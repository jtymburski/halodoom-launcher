/**
 * Game type enumerators, for various configuration options. Bridges the gap between the
 * UI and the controller with key IDs.
 */
#ifndef GAMETYPES_H
#define GAMETYPES_H

enum Bot {
  AVALON = 100,
  NEXIAM = 101,
  RAMSUS = 102,
  UZZIEL = 103,
  ZETSUI = 104
};

enum Map {
  FLOOD_GULCH = 200,
  GHOST_SHIP  = 201,
  REBELLION   = 202,
  SUBMERGED   = 203,
  WAREHOUSE   = 204
};

enum Mode {
  FIESTA         = 300,
  SLAYER         = 301,
  SHOTTY_SHIPERS = 302,
  SWAT           = 303,
  SWORDS         = 304
};

#endif // GAMETYPES_H
