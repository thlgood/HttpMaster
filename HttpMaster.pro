TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    setuptcp.cpp \
    default.cpp \
    config.cpp

HEADERS += \
    core.h \
    config.h \
    setuptcp.h

LIBS = -lglib-2.0 -lpthread

INCLUDEPATH += /usr/include/glib-2.0 \
 /usr/lib/x86_64-linux-gnu/glib-2.0/include
