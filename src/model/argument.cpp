/**
 * @class Argument
 *
 * Argument that can be passed to zandronum to modify the configuration of the launched
 * application.
 */
#include "model/argument.h"

/**
 * Blank constructor, with empty key and no values.
 */
Argument::Argument()
{
}

/**
 * Create the key-value pair for the argument which returns the immutable object.
 * @param key argument key string
 * @param value argument value string
 */
Argument::Argument(const QString &key, const QString &value)
{
  this->key = key;
  this->values.append(value);
}

/**
 * Create the key-value pair for the argument which returns the immutable object. It adds a list
 * of values all tied to the same key.
 * @param key argument key string
 * @param values argument value list of strings
 */
Argument::Argument(const QString &key, const QList<QString> &values)
{
  this->key = key;
  this->values = values;
}

/**
 * Create the key-value pair for the argument which returns the immutable object. This takes
 * an existing Argument and adds one more value.
 * @param arg existing argument
 * @param value argument value string
 */
Argument::Argument(const Argument &arg, const QString &value)
        : Argument(arg.getKey(), arg.getValues())
{
  this->values.append(value);
}

/**
 * Returns the stored immutable key, tied to the {@link #getValue()}.
 * @return key string
 */
QString Argument::getKey() const
{
  return key;
}

/**
 * Returns the stored immutable values, all tied to the {@link #getKey()}.
 * @return value string
 */
QList<QString> Argument::getValues() const
{
  return values;
}
