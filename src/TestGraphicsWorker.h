#ifndef TESTGRAPHICSWORKER_H
#define TESTGRAPHICSWORKER_H

#include "engine/includes.h"
#include "engine/modules/opengl/includes.h"

#include <engine/modules/opengl/GLFWOpenGLModule.h>

using namespace engine::modules::opengl;

#include <GL/glew.h>

#include <GLFW/glfw3.h>

class TestGraphicsWorker : public engine::GraphicsWorker {
public:
    TestGraphicsWorker(engine::Core* core, engine::Module* module, std::string name = "test graphics worker");
    virtual ~TestGraphicsWorker();

    virtual void draw(unsigned microseconds);

private:
    engine::modules::opengl::GLSLProgram shaderProgram;
    GLuint vboId, vaoId;
    //    const char* vertexShaderSource =
    //        R"(#version 330 core
    //        layout (location = 0) in vec3 aPos;
    //        void main()
    //        {
    //            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    //        })";
    const char* vertexShaderSource =
        R"(

            layout (location = 0) in vec4 offset;
            layout (location = 1) in vec4 color;

            out VS_OUT
            {
                vec4 color;
            } vs_out;

            void main()
            {
                const vec4 vertices[3] = vec4[3](vec4(0.25, -0.25, 0.5, 1.0), vec4(-0.25, -0.25, 0.5, 1.0), vec4(0.25, 0.25, 0.5, 0.1));

                gl_Position = vertices[gl_VertexID] + offset;

                vs_out.color = color;
            })";
    const char* tesselationControlShaderSource =
        R"(
            layout (vertices = 3) out;

            void main(void)
            {
            if(gl_InvocationID == 0) {
            gl_TessLevelInner[0] = 5.0;
            gl_TessLevelOuter[0] = 5.0;
            gl_TessLevelOuter[1] = 5.0;
            gl_TessLevelOuter[2] = 5.0;
            }
            gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
            )";
    const char* fragmentShaderSource =
        R"(
        in VS_OUT
        {
            vec4 color;
        } fs_in;

        out vec4 color;

        void main()
        {
            color = fs_in.color; // vec4(1.0f, 0.0f, 0.0f, 1.0f);
        })";

    GLFWOpenGLModule* glfwOpenGLModule;
};

#endif // TESTGRAPHICSWORKER_H
