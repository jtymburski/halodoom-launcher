#ifndef MACLAUNCHCONFIG_H
#define MACLAUNCHCONFIG_H

#include <QCoreApplication>

#include "game/config/launchconfig.h"

class MacLaunchConfig : public LaunchConfig
{
public:
  /* Destructor function */
  ~MacLaunchConfig() override;

private:
  /* Returns the base executable directory */
  QString getBaseExecutableDirectory() const override;

public:
  /* Returns the file reference to the zandronum binary */
  QString getZandronumBinaryFilepath() const override;
};

#endif // MACLAUNCHCONFIG_H
