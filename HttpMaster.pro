TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    setuptcp.cpp \
    default.cpp \
    config.cpp \
    work_thread.cpp \
    conn_manager.cpp \
    feed_conn.cpp \
    http_head.cpp

HEADERS += \
    core.h \
    config.h \
    setuptcp.h \
    work_thread.h \
    conn_manager.h \
    feed_conn.h \
    http_head.h

LIBS = -lglib-2.0 -lpthread

INCLUDEPATH += /usr/include/glib-2.0 \
 /usr/lib/x86_64-linux-gnu/glib-2.0/include
