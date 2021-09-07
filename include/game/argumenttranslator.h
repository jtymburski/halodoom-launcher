/**
 * @class ArgumentTranslator
 *
 * Argument translator that handles taking the {@link Argument} and translating it into
 * other forms, like {@link QStringList}.
 */
#ifndef ARGUMENTTRANSLATOR_H
#define ARGUMENTTRANSLATOR_H

#include "model/argument.h"

class ArgumentTranslator
{
public:
  /* Converts a list of arguments to a serialized string list */
  QStringList toStringList(const QList<Argument> &arguments);
};

#endif // ARGUMENTTRANSLATOR_H
