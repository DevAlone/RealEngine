#ifndef TESTGRAPHICSWORKER_H
#define TESTGRAPHICSWORKER_H

#include "engine/includes.h"

#include <engine/modules/GLFWOpenGLModule.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

class TestGraphicsWorker : public engine::GraphicsWorker {
public:
    TestGraphicsWorker(engine::Core* core, engine::Module* module, std::string name = "test graphics worker");
    virtual ~TestGraphicsWorker();

    virtual void draw(unsigned microseconds);

private:
    int shaderProgramId;
    unsigned int vboId, vaoId;
    const char* vertexShaderSource =
        R"(#version 330 core
        layout (location = 0) in vec3 aPos;
        void main()
        {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        })";
    const char* fragmentShaderSource =
        R"(#version 330 core
        out vec4 FragColor;
        void main()
        {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        })";

    engine::modules::GLFWOpenGLModule* glfwOpenGLModule;
};

#endif // TESTGRAPHICSWORKER_H
