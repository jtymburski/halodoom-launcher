/**
 * @class ArgumentTranslator
 *
 * Argument translator that handles taking the {@link Argument} and translating it into
 * other forms, like {@link QStringList}.
 */
#include "game/argumenttranslator.h"

/* ---- PRIVATE FUNCTIONS ---- */

/* Translate game bot type to argument value */
QString ArgumentTranslator::botToArgValue(const Bot &bot)
{
  switch(bot)
  {
    case Bot::RAMSUS:
      return "ramsus";
    case Bot::ZETSUI:
      return "zetsui";
    case Bot::NEXIAM:
      return "nexiam";
    case Bot::UZZIEL:
      return "uzziel";
    case Bot::AVALON:
      return "avalon";
    case Bot::GLUMPY:
      return "glumpy";
    case Bot::SCLUGGS:
     return "scluggs";
    case Bot::PINKLETON:
     return "pinkleton";
    case Bot::BOOPSTER:
      return "boopster";
    case Bot::JOHN:
      return "john";
    case Bot::WASP:
      return "wasp";
    case Bot::GOLDRUNNER:
      return "goldrunner";
    case Bot::FILCH:
      return "filch";
    case Bot::ASCENDANT:
      return "ascendant";
    case Bot::OCEANMAN:
      return "oceanman";
     default:
      throw std::domain_error("Unsupported bot=" + std::to_string(bot)
                              + " for argument translator");
  }
}

/* ---- PUBLIC FUNCTIONS ---- */

/* Translate game bot type to argument */
Argument ArgumentTranslator::bots(const QVector<Bot> &bots)
{
  QList<QString> bot_args;
  for(auto const &bot : qAsConst(bots))
      bot_args.append(botToArgValue(bot));
  return Argument("+addbot", bot_args);
}

/* Translate game map type to argument */
Argument ArgumentTranslator::map(const Map &map)
{
  QString map_arg;
  switch(map)
  {
    case Map::LOCKUP:
      map_arg = "multi01";
      break;
    case Map::WAREHOUSE:
      map_arg = "multi02";
      break;
    case Map::SUBMERGED:
      map_arg = "multi04";
      break;
    case Map::REBELLION:
      map_arg = "multi05";
      break;
    case Map::GHOSTSHIP:
      map_arg = "multi06";
      break;
    case Map::LIMINAL:
      map_arg = "multi08";
      break;
    case Map::FLOOD_GULCH:
      map_arg = "multi09";
      break;
    case Map::VERDANT:
      map_arg = "multi12";
      break;
    case Map::TERMINUS:
      map_arg = "multi13";
      break;
    case Map::SCHISM:
      map_arg = "dave02";
      break;
    case Map::THRESHOLD:
      map_arg = "multi15";
      break;
    case Map::TRIGATE:
      map_arg = "multi16";
      break;
    case Map::INFINITE:
      map_arg = "multi17";
      break;
    default:
      throw std::domain_error("Unsupported map=" + std::to_string(map)
                              + " for argument translator");
  }
  return Argument("+addmap", map_arg);
}

/* Translate game mode type to argument */
Argument ArgumentTranslator::mode(const Mode &mode)
{
  QString mode_arg;
  switch(mode)
  {
    case Mode::SLAYER:
      mode_arg = "0";
      break;
    case Mode::ODDBALL:
      mode_arg = "1";
      break;
    case Mode::KINGOFTHEHILL:
      mode_arg = "2";
      break;
    case Mode::JUGGERNAUT:
      mode_arg = "3";
      break;
    case Mode::INFECTION:
      mode_arg = "4";
      break;
    case Mode::SWAT:
      mode_arg = "5";
      break;
    default:
      throw std::domain_error("Unsupported mode=" + std::to_string(mode)
                              + " for argument translator");
  }
  return Argument(" set menu_objective ", mode_arg);
}


/* Translate loadout to argument */
Argument ArgumentTranslator::loadOut(const LoadOut &loadout)
{
  QString mode_arg;
  switch(loadout)
  {
    case LoadOut::STANDARD:
      mode_arg = "0";
      break;
    case LoadOut::HARDCORE:
      mode_arg = "1";
      break;
    case LoadOut::FIESTA:
      mode_arg = "2";
      break;
    case LoadOut::SMALLARMS:
      mode_arg = "3";
      break;
    case LoadOut::SNIPERS:
      mode_arg = "4";
      break;
    case LoadOut::HOTNHEAVY:
      mode_arg = "5";
      break;
    case LoadOut::SWORDS:
      mode_arg = "6";
      break;
    case LoadOut::SHOTTYSNIPERS:
      mode_arg = "7";
      break;
    case LoadOut::SLICENDICE:
      mode_arg = "8";
      break;
    case LoadOut::UNSC:
      mode_arg = "9";
      break;
    case LoadOut::COVENANT:
      mode_arg = "10";
      break;
    case LoadOut::BRUTE:
      mode_arg = "11";
      break;
    default:
      throw std::domain_error("Unsupported mode=" + std::to_string(loadout)
                              + " for argument translator");
  }
  return Argument(" set menu_skirmishloadout ", mode_arg);
}

/* Translate max player count to argument */
Argument ArgumentTranslator::playerCount(int count)
{
  return Argument("+sv_maxplayers", QString::number(count));
}

/* Translate game score limit to argument */
Argument ArgumentTranslator::scoreLimit(int limit)
{
  return Argument(" set menu_skirmishfraglimit ", QString::number(limit));
}

/* Translate game time limit to argument */
Argument ArgumentTranslator::timeLimit(int limit)
{
  return Argument(" set menu_skirmishtimelimit ", QString::number(limit));
}

/* Translate game time score limit to argument */
Argument ArgumentTranslator::timeScoreLimit(int limit)
{
  return Argument(" set menu_skirmishtimescorelimit ", QString::number(limit));
}

/* Translate team configuration to argument */
Argument ArgumentTranslator::teamGame(int team)
{
    if(team==3)
        return Argument(" teamplay false "," set menu_skirmishgamemode 3 ");
    else
        return Argument(" teamplay true "," set menu_skirmishgamemode 4 ");
}


/**
 * Converts a list of arguments to a serialized string list, where each Key and Value is
 * represented in the list as separate strings.
 * @param arguments ordered list of arguments
 * @return string list of the contents in all arguments
 */
QStringList ArgumentTranslator::toStringList(const QList<Argument> &arguments)
{
  QStringList argumentStringList;

  for(auto const &arg : arguments)
  {
    const QList<QString> arg_values = arg.getValues();
    for(auto const &arg_val : arg_values)
    {
      argumentStringList.append(arg.getKey());
      argumentStringList.append(arg_val);
    }
  }
  argumentStringList.append("+exec blah.cfg");
  return argumentStringList;
}

