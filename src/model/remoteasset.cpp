/**
 * @class RemoteAsset
 *
 * Remote asset defining a file available from a bucket accessible through a URL.
 */
#include "model/remoteasset.h"

/* Returns the unique hash */
QString RemoteAsset::getHash() const
{
  return hash;
}

/* Returns the file name */
QString RemoteAsset::getName() const
{
  return name;
}

/* Returns the file URL */
QString RemoteAsset::getUrl() const
{
  return url;
}

/* Returns the asset version */
int RemoteAsset::getVersion() const
{
  return version;
}

/**
 * Build the {@link RemoteAsset} object from the configured builder.
 * @return built object
 */
RemoteAsset RemoteAsset::Builder::build()
{
  RemoteAsset asset;

  asset.hash = this->hash;
  asset.name = this->name;
  asset.url = this->url;
  asset.version = this->version;

  return asset;
}

/* Sets the unique hash */
RemoteAsset::Builder* RemoteAsset::Builder::setHash(QString hash)
{
  this->hash = hash;
  return this;
}

/* Sets the file name */
RemoteAsset::Builder* RemoteAsset::Builder::setName(QString name)
{
  this->name = name;
  return this;
}

/* Sets the file URL */
RemoteAsset::Builder* RemoteAsset::Builder::setUrl(QString url)
{
  this->url = url;
  return this;
}

/* Sets the asset version */
RemoteAsset::Builder* RemoteAsset::Builder::setVersion(int version)
{
  this->version = version;
  return this;
}
