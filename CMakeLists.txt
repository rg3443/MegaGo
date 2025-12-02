cmake_minimum_required(VERSION 3.5)

project(MegaGo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        ginclude.h

        model/programstate.h
        model/programstate.cpp
        model/gvar.h
        model/gvar.cpp
        model/basemodelobject.h
        model/basemodelobject.cpp

        model/actors/field.cpp
        model/actors/field.h
        model/actors/tile.h
        model/actors/tile.cpp
        model/actors/token.h
        model/actors/token.cpp
        model/actors/allience.h
        model/actors/allience.cpp

        model/gameloop/player.h
        model/gameloop/player.cpp
        model/gameloop/gamemode.h
        model/gameloop/gamemode.cpp
        model/gameloop/team.h
        model/gameloop/team.cpp

        model/accounts/clientaccount.h
        model/accounts/clientaccount.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MegaGo
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MegaGo APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MegaGo SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MegaGo
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MegaGo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(MegaGo PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MegaGo)
endif()
