TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    engine/exceptions/UnableToDetermineWorkerType.cpp \
    engine/modules/opengl/exceptions/UnableToCompileGLSLShader.cpp \
    engine/modules/opengl/exceptions/UnableToLinkGLSLProgram.cpp \
    engine/modules/opengl/GLFWOpenGLModule.cpp \
    engine/modules/opengl/GLSLFragmentShader.cpp \
    engine/modules/opengl/GLSLShader.cpp \
    engine/modules/opengl/GLSLVertexShader.cpp \
    engine/Core.cpp \
    engine/GraphicsWorker.cpp \
    engine/Module.cpp \
    engine/Worker.cpp \
    main.cpp \
    TestGraphicsWorker.cpp \
    engine/modules/opengl/GLSLProgram.cpp
LIBS += -lGLEW -lglfw -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread


DEFINES += LINUX

HEADERS += \
    engine/exceptions/forwards.h \
    engine/exceptions/includes.h \
    engine/exceptions/UnableToDetermineWorkerType.h \
    engine/graphics_workers/forwards.h \
    engine/graphics_workers/includes.h \
    engine/modules/opengl/exceptions/forwards.h \
    engine/modules/opengl/exceptions/includes.h \
    engine/modules/opengl/exceptions/UnableToCompileGLSLShader.h \
    engine/modules/opengl/exceptions/UnableToLinkGLSLProgram.h \
    engine/modules/opengl/forwards.h \
    engine/modules/opengl/GLFWOpenGLModule.h \
    engine/modules/opengl/GLSLFragmentShader.h \
    engine/modules/opengl/GLSLShader.h \
    engine/modules/opengl/GLSLVertexShader.h \
    engine/modules/opengl/includes.h \
    engine/workers/forwards.h \
    engine/workers/includes.h \
    engine/Core.h \
    engine/forwards.h \
    engine/GraphicsWorker.h \
    engine/includes.h \
    engine/Module.h \
    engine/Worker.h \
    TestGraphicsWorker.h \
    engine/modules/opengl/GLSLProgram.h
