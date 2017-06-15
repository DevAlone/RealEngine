#ifndef TESTGRAPHICSWORKER_H
#define TESTGRAPHICSWORKER_H

#include "engine/includes.h"

#include <engine/modules/opengl/GLFWOpenGLModule.h>

using engine::modules::opengl::GLFWOpenGLModule;

#include <GL/glew.h>

#include <GLFW/glfw3.h>

class TestGraphicsWorker : public engine::GraphicsWorker {
public:
    TestGraphicsWorker(engine::Core* core, engine::Module* module, std::string name = "test graphics worker");
    virtual ~TestGraphicsWorker();

    virtual void draw(unsigned microseconds);

private:
    GLuint shaderProgramId;
    GLuint vboId, vaoId;
    //    const char* vertexShaderSource =
    //        R"(#version 330 core
    //        layout (location = 0) in vec3 aPos;
    //        void main()
    //        {
    //            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    //        })";
    const char* vertexShaderSource =
        R"(#version 330 core

        layout (location = 0) in vec4 offset;

        void main()
        {
            const vec4 vertices[3] = vec4[3](vec4(0.25, -0.25, 0.5, 1.0), vec4(-0.25, -0.25, 0.5, 1.0), vec4(0.25, 0.25, 0.5, 0.1));

            gl_Position = vertices[gl_VertexID] + offset;
        })";
    const char* fragmentShaderSource =
        R"(#version 330 core
        out vec4 color;
        void main()
        {
            color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
        })";

    GLFWOpenGLModule* glfwOpenGLModule;
};

#endif // TESTGRAPHICSWORKER_H
