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
    case Bot::AVALON:
      return "avalon";
    case Bot::NEXIAM:
      return "nexiam";
    case Bot::RAMSUS:
      return "ramsus";
    case Bot::UZZIEL:
      return "uzziel";
    case Bot::ZETSUI:
      return "zetsui";
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
    case Map::FLOOD_GULCH:
      map_arg = "MULTI07";
      break;
    case Map::GHOST_SHIP:
      map_arg = "MULTI06";
      break;
    case Map::REBELLION:
      map_arg = "MULTI05";
      break;
    case Map::SUBMERGED:
      map_arg = "MULTI04";
      break;
    case Map::WAREHOUSE:
      map_arg = "MULTI02";
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
    case Mode::FIESTA:
      mode_arg = "1";
      break;
    case Mode::SHOTTY_SHIPERS:
      mode_arg = "0";
      break;
    case Mode::SLAYER:
      mode_arg = "2";
      break;
    case Mode::SWAT:
      mode_arg = "4";
      break;
    case Mode::SWORDS:
      mode_arg = "3";
      break;
    default:
      throw std::domain_error("Unsupported mode=" + std::to_string(mode)
                              + " for argument translator");
  }
  return Argument("+skill", mode_arg);
}

/* Translate max player count to argument */
Argument ArgumentTranslator::playerCount(int count)
{
  return Argument("+sv_maxplayers", QString::number(count));
}

/* Translate game score limit to argument */
Argument ArgumentTranslator::scoreLimit(int limit)
{
  return Argument("+fraglimit", QString::number(limit));
}

/* Translate game time limit to argument */
Argument ArgumentTranslator::timeLimit(int limit)
{
  return Argument("+timelimit", QString::number(limit));
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

  return argumentStringList;
}
