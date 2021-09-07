/**
 * @class FileReader
 *
 * Interface to handle any file processing and abstract out the implementation details.
 */
#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QJsonDocument>

class FileReader
{
public:
  /* Returns if the path is a valid file that can be read */
  static bool isValid(QString path);

  /* Reads the file at a given path and returns the contents as a parsed JSON document */
  static QJsonDocument readFileToJson(QString path);

  /* Reads the file at a given path and returns the contents in a string */
  static QString readFileToString(QString path);
};

#endif // FILEREADER_H
