TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    engine/modules/GLFWOpenGLModule.cpp \
    engine/Core.cpp \
    engine/GraphicsWorker.cpp \
    engine/Module.cpp \
    engine/Worker.cpp \
    engine/exceptions/UnableToDetermineWorkerType.cpp \
    TestGraphicsWorker.cpp

LIBS += -lGLEW -lglfw -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread


DEFINES += LINUX

HEADERS += \
    engine/includes.h \
    engine/forwards.h \
    engine/modules/forwards.h \
    engine/exceptions/forwards.h \
    engine/exceptions/includes.h \
    engine/graphics_workers/forwards.h \
    engine/graphics_workers/includes.h \
    engine/modules/includes.h \
    engine/workers/forwards.h \
    engine/workers/includes.h \
    engine/modules/GLFWOpenGLModule.h \
    engine/Core.h \
    engine/GraphicsWorker.h \
    engine/Module.h \
    engine/Worker.h \
    TestGraphicsWorker.h \
    engine/exceptions/UnableToDetermineWorkerType.h
