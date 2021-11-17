/**
 * @class Database
 *
 * User interface database of commonly accessed and re-used components.
 */
#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
#include <QMap>

#include "model/gametypes.h"
#include "ui/model/selection.h"

class Database
{
public:
  /* Constructor */
  Database();

private:
  /* Full set of available maps */
  QMap<Map, Selection> maps;

  /* Full set of available modes */
  QMap<Mode, Selection> modes;

private:
  /* Build all available maps and cache internally */
  void buildMaps();

  /* Build all available modes and cache internally */
  void buildModes();

public:
  /* Return a UI selection for a given map */
  Selection getMap(Map map_id);

  /* Return all available map UI selections */
  QList<Selection> getMaps();

  /* Return a UI selection for a given mode */
  Selection getMode(Mode mode_id);

  /* Return all available mode UI selections */
  QList<Selection> getModes();
};

#endif // DATABASE_H
