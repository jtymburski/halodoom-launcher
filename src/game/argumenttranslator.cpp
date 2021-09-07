/**
 * @class ArgumentTranslator
 *
 * Argument translator that handles taking the {@link Argument} and translating it into
 * other forms, like {@link QStringList}.
 */
#include "game/argumenttranslator.h"

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
