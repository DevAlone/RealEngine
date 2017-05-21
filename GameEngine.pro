TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    engine/exceptions/unabletodetermineworkertype.cpp \
    engine/workers/worker.cpp \
    engine/core.cpp \
    engine/modules/module.cpp

LIBS += -lGLEW -lglfw -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread


DEFINES += LINUX

HEADERS += \
    engine/exceptions/unabletodetermineworkertype.h \
    engine/workers/worker.h \
    engine/core.h \
    engine/modules/module.h \
    engine/modules/modules.h \
    engine/exceptions/exceptions.h \
    engine/workers/workers.h
