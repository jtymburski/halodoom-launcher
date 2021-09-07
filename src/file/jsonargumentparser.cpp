/**
 * @class JsonArgumentParser
 *
 * Parser to convert JSON into the Argument model.
 */
#include "file/jsonargumentparser.h"

/**
 * Parses and converts the top level array to a list of strings. This will ONLY read strings
 * from the array, all other types are discarded.
 * @param json_array json array object containing the strings
 * @param array_key the key that was used to fetch this array. Used for logging only
 * @return list of strings found in the array
 */
QList<QString> JsonArgumentParser::parseStrings(QJsonArray json_array, QString array_key)
{
  QList<QString> values;

  const QList<QVariant> elements = json_array.toVariantList();
  for(auto const &element : elements)
  {
    if(element.type() == QVariant::Type::String)
      values.append(element.toString());
    else if(element.isValid())
      qWarning() << "[WARNING] Key=" << array_key
                 << "for the JSON array contains an element of unsupported type ="
                 << element.type();
  }

  return values;
}

/* ---- PUBLIC FUNCTIONS ---- */

/**
 * Parses and converts the top level object at the prefix key to a list of arguments. It only
 * processes Bools, Doubles, Strings, and Arrays of Strings into arguments.
 * @param json top level JSON object
 * @param prefix_key the prefix key for the first nested object to fetch the arguments
 * @return list of arguments generated from that prefix
 */
QList<Argument> JsonArgumentParser::parseArguments(QJsonDocument json, QString prefix_key)
{
  QList<Argument> arguments;

  // Try to fetch the prefix at the top level object
  const QJsonObject json_object = json.object();
  const QJsonValue prefix_value = json_object.value(prefix_key);
  if(!prefix_value.isObject() && !prefix_value.isUndefined())
    qWarning() << "[WARNING] Prefix key =" << prefix_key
               << " in JSON document is not an object and instead type =" << prefix_value.type();

  // Using the prefix object, try to assemble a list of arguments
  const QJsonObject prefix_object = prefix_value.toObject();
  const QList<QString> keys = prefix_object.keys();
  for(auto const &key : keys) {
      const QJsonValue value = prefix_object.value(key);
      switch(value.type())
      {
        case QJsonValue::Type::Bool:
          arguments.append(Argument(key, value.toVariant().toString()));
          break;
        case QJsonValue::Type::Double:
          arguments.append(Argument(key, QString::number(value.toDouble(), 'f', 2)));
          break;
        case QJsonValue::Type::String:
          arguments.append(Argument(key, value.toString()));
          break;
        case QJsonValue::Type::Array:
          arguments.append(Argument(key, parseStrings(value.toArray(), key)));
          break;
        default:
          qWarning() << "[WARNING] Found key =" << key
                     << " in JSON prefix object was unsupported type =" << value.type();
      }
  }

  return arguments;
}
