TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    engine/exceptions/unabletodetermineworkertype.cpp \
    engine/worker.cpp \
    engine/core.cpp \
    engine/module.cpp \
    engine/graphicsmodule.cpp \
    engine/graphicsworker.cpp

LIBS += -lGLEW -lglfw -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread


DEFINES += LINUX

HEADERS += \
    engine/exceptions/unabletodetermineworkertype.h \
    engine/worker.h \
    engine/core.h \
    engine/module.h \
    engine/graphicsmodule.h \
    engine/graphicsworker.h \
    engine/modules/modules.i \
    engine/engine.i \
    engine/workers/workers.i \
    engine/graphics_modules/graphics_modules.i \
    engine/graphics_workers/graphics_workers.i \
    engine/exceptions/exceptions.i
