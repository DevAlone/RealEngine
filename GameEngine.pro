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
    engine/graphicsworker.cpp \
    engine/graphics_modules/openglmodule.cpp

LIBS += -lglfw -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread


DEFINES += LINUX

HEADERS += \
    engine/exceptions/unabletodetermineworkertype.h \
    engine/worker.h \
    engine/core.h \
    engine/module.h \
    engine/graphicsmodule.h \
    engine/graphicsworker.h \
    engine/graphics_modules/openglmodule.h \
    engine/includes.h \
    engine/forwards.h \
    engine/graphics_modules/forwards.h \
    engine/graphics_modules/includes.h \
    engine/modules/forwards.h \
    engine/exceptions/forwards.h \
    engine/exceptions/includes.h \
    engine/graphics_workers/forwards.h \
    engine/graphics_workers/includes.h \
    engine/modules/includes.h \
    engine/workers/forwards.h \
    engine/workers/includes.h
