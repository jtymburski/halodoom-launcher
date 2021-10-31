/**
 * @class ArgumentTranslator
 *
 * Argument translator that handles taking the {@link Argument} and translating it into
 * other forms, like {@link QStringList}.
 */
#ifndef ARGUMENTTRANSLATOR_H
#define ARGUMENTTRANSLATOR_H

#include "model/argument.h"
#include "model/gametypes.h"

class ArgumentTranslator
{
private:
  /* Translate game bot type to argument value */
  QString botToArgValue(const Bot &bot);

public:
  /* Translate game bot type to argument */
  Argument bots(const QVector<Bot> &bots);

  /* Translate game map type to argument */
  Argument map(const Map &map);

  /* Translate game mode type to argument */
  Argument mode(const Mode &mode);

  /* Translate max player count to argument */
  Argument playerCount(int count);

  /* Translate game score limit to argument */
  Argument scoreLimit(int limit);

  /* Translate game time limit to argument */
  Argument timeLimit(int limit);

  /* Converts a list of arguments to a serialized string list */
  QStringList toStringList(const QList<Argument> &arguments);
};

#endif // ARGUMENTTRANSLATOR_H
