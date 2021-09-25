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
    src/ui/maindialog.cpp \
    src/ui/view/create/gamecreateview.cpp \
    src/ui/view/create/gamemapview.cpp \
    src/ui/view/create/gamemodeview.cpp \
    src/ui/view/create/gameoptionsview.cpp \
    src/ui/view/mainview.cpp \
    src/ui/view/multiplayer/multiplayerjoinview.cpp \
    src/ui/view/multiplayer/multiplayermainview.cpp \
    src/ui/view/multiplayer/multiplayerview.cpp \
    src/ui/view/offline/offlineview.cpp \
    src/ui/widget/animatedbackground.cpp \
    src/ui/widget/imagebutton.cpp \
    src/ui/widget/menubutton.cpp \
    src/ui/widget/pageheader.cpp

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
    include/ui/maindialog.h \
    include/ui/view/create/gamecreateview.h \
    include/ui/view/create/gamemapview.h \
    include/ui/view/create/gamemodeview.h \
    include/ui/view/create/gameoptionsview.h \
    include/ui/view/mainview.h \
    include/ui/view/multiplayer/multiplayerjoinview.h \
    include/ui/view/multiplayer/multiplayermainview.h \
    include/ui/view/multiplayer/multiplayerview.h \
    include/ui/view/offline/offlineview.h \
    include/ui/widget/animatedbackground.h \
    include/ui/widget/imagebutton.h \
    include/ui/widget/menubutton.h \
    include/ui/widget/pageheader.h

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
                       $$files($$PWD/resource/executable/generic/*)
  appBinaries.path = Contents/Resources

  QMAKE_BUNDLE_DATA += macBinaries
}

win32 {
  RC_ICONS = icon.ico
  RESOURCES += resources-win.qrc

  appBinaries.files += $$files($$PWD/resource/executable/win/*) \
                       $$files($$PWD/resource/executable/generic/*)
  appBinaries.path = $$OUT_PWD/debug

  COPIES += appBinaries
}
