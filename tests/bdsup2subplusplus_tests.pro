QT += core testlib
CONFIG += qt6 console c++17

TARGET = bdsup2subplusplus_tests
TEMPLATE = app

SOURCES += test_palette.cpp \
    ../src/Subtitles/palette.cpp

INCLUDEPATH += ../src
