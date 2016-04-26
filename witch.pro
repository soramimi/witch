TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    FileUtil.cpp \
    pathcat.cpp

HEADERS += \
    FileUtil.h \
    pathcat.h \
    pathcat_.h

