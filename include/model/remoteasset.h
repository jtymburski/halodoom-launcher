/**
 * @class RemoteAsset
 *
 * Remote asset defining a file available from a bucket accessible through a URL.
 */
#ifndef REMOTEASSET_H
#define REMOTEASSET_H

#include <QString>

class RemoteAsset
{
public:
  class Builder;

private:
  /* Private blank constructor, use {@link Builder} */
  RemoteAsset() = default;

  /* Unique hash for the file stored at the URL */
  QString hash;

  /* File name */
  QString name;

  /* URL to access the file */
  QString url;

  /* Remote version of the asset. Ordered, higher indicates more recent */
  uint version = 0;

public:
  /* Returns the unique hash */
  QString getHash() const;

  /* Returns the file name */
  QString getName() const;

  /* Returns the file URL */
  QString getUrl() const;

  /* Returns the asset version */
  int getVersion() const;

  /* Builder nested class for constructing the immutable object */
  class Builder
  {
  private:
    QString hash;
    QString name;
    QString url;
    uint version;

  public:
    RemoteAsset build();
    Builder* setHash(QString hash);
    Builder* setName(QString name);
    Builder* setUrl(QString url);
    Builder* setVersion(int version);
  };
};

#endif // REMOTEASSET_H
