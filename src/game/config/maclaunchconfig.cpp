#include "game/config/maclaunchconfig.h"

/* Destructor function */
MacLaunchConfig::~MacLaunchConfig()
{
}

/* Returns the base executable directory */
QString MacLaunchConfig::getBaseExecutableDirectory() const
{
  return QCoreApplication::applicationDirPath() + "/../Resources/";
}

/* Returns the file reference to the zandronum binary */
QString MacLaunchConfig::getZandronumBinaryFilepath() const
{
  return getBaseExecutableDirectory() + "Zandronum.app/Contents/MacOS/zandronum";
}
