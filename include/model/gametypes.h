/**
 * Game type enumerators, for various configuration options. Bridges the gap between the
 * UI and the controller with key IDs.
 */
#ifndef GAMETYPES_H
#define GAMETYPES_H

enum Bot {
  RAMSUS = 100,
  ZETSUI = 101,
  NEXIAM = 102,
  UZZIEL = 103,
  AVALON = 104,
  GLUMPY = 105,
  SCLUGGS = 106,
  PINKLETON = 107,
  BOOPSTER = 108,
  JOHN = 109,
  WASP = 110,
  GOLDRUNNER = 111,
  FILCH = 112,
  ASCENDANT = 113,
  OCEANMAN = 114
};

enum Map {
  LOCKUP = 200,
  WAREHOUSE  = 201,
  SUBMERGED   = 202,
  REBELLION   = 203,
  GHOSTSHIP   = 204,
  LIMINAL   = 205,
  FLOOD_GULCH   = 206,
  VERDANT   = 207,
  TERMINUS   = 208,
  SCHISM   = 209,
  THRESHOLD   = 210,
  TRIGATE   = 211,
  INFINITE   = 212
};

enum Mode {
  SLAYER         = 300,
  ODDBALL        = 301,
  KINGOFTHEHILL  = 302,
  JUGGERNAUT     = 303,
  INFECTION      = 304,
  SWAT           = 305
};

enum LoadOut {
  STANDARD       = 400,
  HARDCORE       = 401,
  FIESTA         = 402,
  SMALLARMS      = 403,
  SNIPERS        = 404,
  HOTNHEAVY      = 405,
  SWORDS         = 406,
  SHOTTYSNIPERS  = 407,
  SLICENDICE     = 408,
  UNSC           = 409,
  COVENANT       = 410,
  BRUTE          = 411
};
#endif // GAMETYPES_H
