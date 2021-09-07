QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 file_copies

SOURCES += \
    src/file/filereader.cpp \
    src/file/jsonargumentparser.cpp \
    src/game/argumenttranslator.cpp \
    src/game/config/launchconfig.cpp \
    src/game/config/maclaunchconfig.cpp \
    src/game/config/winlaunchconfig.cpp \
    src/game/gamecontroller.cpp \
    src/main.cpp \
    src/model/argument.cpp \
    src/network/networkinfo.cpp \
    src/ui/maindialog.cpp

HEADERS += \
    include/file/filereader.h \
    include/file/jsonargumentparser.h \
    include/game/argumenttranslator.h \
    include/game/config/launchconfig.h \
    include/game/config/maclaunchconfig.h \
    include/game/config/winlaunchconfig.h \
    include/game/gamecontroller.h \
    include/model/argument.h \
    include/network/networkinfo.h \
    include/ui/maindialog.h

INCLUDEPATH += \
    include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

# Resources

RESOURCES += \
  resources.qrc

appBinaries.files = $$PWD/resource/config.json
macx {
  ICON = icon.icns
  RESOURCES += resources-mac.qrc

  appBinaries.files += $$PWD/resource/executable/mac/Zandronum.app \
                       $$files($$PWD/resource/executable/generic/*) \
  appBinaries.path = Contents/Resources
  QMAKE_BUNDLE_DATA += appBinaries
}

win32 {
  RC_ICONS = icon.ico
  RESOURCES += resources-win.qrc

  appBinaries.files += $$files($$PWD/resource/executable/win/*) \
                       $$files($$PWD/resource/executable/generic/*)
  appBinaries.path = $$OUT_PWD/debug

  COPIES += appBinaries
}
