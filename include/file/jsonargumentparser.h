/**
 * @class JsonArgumentParser
 *
 * Parser to convert JSON into the Argument model.
 */
#ifndef JSONARGUMENTPARSER_H
#define JSONARGUMENTPARSER_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QDebug>

#include "model/argument.h"

class JsonArgumentParser
{
private:
  /* Parses and converts the top level array to a list of strings */
  static QList<QString> parseStrings(QJsonArray json_array, QString array_key);

public:
  /* Parses and converts the top level object at the prefix key to a list of arguments */
  static QList<Argument> parseArguments(QJsonDocument json, QString prefix_key);
};

#endif // JSONARGUMENTPARSER_H
