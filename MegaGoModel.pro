QT       += core gui
TEMPLATE = lib
DEFINES += QTSHELL_LIBRARY

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    model/programstate.cpp \
    model/gvar.cpp \
    model/basemodelobject.cpp \
    model/actors/field.cpp \
    model/actors/tile.cpp \
    model/actors/token.cpp \
    model/actors/allience.cpp \
    model/gameloop/player.cpp \
    model/gameloop/gamemode.cpp \
    model/gameloop/team.cpp \
    model/accounts/clientaccount.cpp \
    model/server/room.cpp \
    utils/glossar/glossar.cpp

HEADERS += \
    mainwindow.h \
    ginclude.h \
    model/programstate.h \
    model/gvar.h \
    model/basemodelobject.h \
    model/actors/field.h \
    model/actors/tile.h \
    model/actors/token.h \
    model/actors/allience.h \
    model/gameloop/player.h \
    model/gameloop/gamemode.h \
    model/gameloop/team.h \
    model/accounts/clientaccount.h \
    model/server/room.h \
    utils/glossar/glossar.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
!isEmpty(target.path): INSTALLS += target
