#include "game/config/winlaunchconfig.h"

/* Destructor function */
WinLaunchConfig::~WinLaunchConfig()
{
}

/* Returns the base executable directory */
QString WinLaunchConfig::getBaseExecutableDirectory() const
{
  return QCoreApplication::applicationDirPath() + QDir::separator();
}

/* Returns the file reference to the zandronum binary */
QString WinLaunchConfig::getZandronumBinaryFilepath() const
{
  return getBaseExecutableDirectory() + "zandronum.exe";
}
