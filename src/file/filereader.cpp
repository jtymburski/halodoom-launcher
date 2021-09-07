/**
 * @class FileReader
 *
 * Interface to handle any file processing and abstract out the implementation details.
 */
#include "file/filereader.h"

/**
 * Returns if the path is a valid file that can be read.
 * @param path a direct or relative file url
 * @return TRUE if the file is valid and could be read. FALSE otherwise
 */
bool FileReader::isValid(QString path)
{
  return QFile(path).exists();
}

/**
 * Reads the file at a given path and returns the contents as a parsed JSON document. If the
 * contents is not a valid JSON object, it will return a blank QJsonDocument (isNull()=true).
 * @param path a direct or relative file url
 * @return full contents of file as JSON or blank if no file or invalid
 */
QJsonDocument FileReader::readFileToJson(QString path)
{
  QJsonDocument doc;

  QString fileContents = readFileToString(path);
  if(!fileContents.isEmpty())
  {
    QJsonParseError error;
    doc = QJsonDocument::fromJson(fileContents.toUtf8(), &error);
    if(doc.isNull())
      qWarning() << "[WARNING] Failed to parse config file =" << path
                 << " to json with error =" << error.errorString();
  }

  return doc;
}

/**
 * Reads the file at a given path and returns the contents in a string.
 * @param path a direct or relative file url
 * @return full contents of file, blank if empty or if file not a valid path
 */
QString FileReader::readFileToString(QString path)
{
  QString contents;

  QFile file(path);
  if(file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    contents = file.readAll();
    file.close();
  }
  else
  {
    qWarning() << "[WARNING] Failed to open config file =" << path
               << " with error =" << file.errorString();
  }

  return contents;
}
