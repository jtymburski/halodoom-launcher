/**
 * @class Argument
 *
 * Argument that can be passed to zandronum to modify the configuration of the launched
 * application.
 */
#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <QList>
#include <QString>

class Argument
{
public:
  /* Constructor, blank */
  Argument();

  /* Constructor, with single value */
  Argument(const QString &key, const QString &value);

  /* Constructor, with more than one value */
  Argument(const QString &key, const QList<QString> &values);

  /* Constructor, adding one value to an existing argument list of values */
  Argument(const Argument &arg, const QString &value);

private:
  /* Key name of the argument */
  QString key;

  /* Values of the argument */
  QList<QString> values;

public:
  /* Returns the key name of the argument */
  QString getKey() const;

  /* Returns the values of the argument */
  QList<QString> getValues() const;
};

#endif // ARGUMENT_H
