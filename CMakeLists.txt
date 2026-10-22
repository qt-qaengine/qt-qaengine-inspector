# SPDX-License-Identifier: PolyForm-Noncommercial-1.0.0
# Copyright (c) 2026 Andrei Kozhevnikov <coderusinbox@gmail.com>

cmake_minimum_required(VERSION 3.16)

project(qt-qaengine-inspector VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(qt-qaengine-inspector
    src/main.cpp
    src/socketconnector.h
    src/socketconnector.cpp
    src/mytreemodel2.h
    src/mytreemodel2.cpp
)

qt_add_qml_module(qt-qaengine-inspector
    URI qtqaengine.inspector
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        SOURCES src/analyzemanager.h src/analyzemanager.cpp
        SOURCES src/analyzemodel.h src/analyzemodel.cpp
)

set_target_properties(qt-qaengine-inspector PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER dev.qtqaengine.inspector
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(qt-qaengine-inspector
    PRIVATE
    Qt6::Quick
    Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS qt-qaengine-inspector
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
