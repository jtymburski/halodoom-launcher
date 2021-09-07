#ifndef WINLAUNCHCONFIG_H
#define WINLAUNCHCONFIG_H

#include <QCoreApplication>
#include <QDir>

#include "game/config/launchconfig.h"

class WinLaunchConfig : public LaunchConfig
{
public:
  /* Destructor function */
  ~WinLaunchConfig() override;

private:
  /* Returns the base executable directory */
  QString getBaseExecutableDirectory() const override;

public:
  /* Returns the file reference to the zandronum binary */
  QString getZandronumBinaryFilepath() const override;
};

#endif // WINLAUNCHCONFIG_H
