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
    GLuint vaoId;
    const char* vertexShaderSource =
        R"(
            layout (location = 0) in vec4 color;

            out VS_OUT
            {
                vec4 color;
            } vs_out;

            void main()
            {
                const vec4 vertices[3] = vec4[3](
        vec4(0, 0, 0.5, 1.0),
        vec4(0.5, 0, 0.5, 1.0),
        vec4(0.5, 0.5, 0.5, 0.1)
        );
//if(gl_VertexID >2) {
//            gl_Position = vec4(-1, -1, 0.5, 1.0);
//            return;
//            }




                gl_Position = vertices[gl_VertexID];

                vs_out.color = color;
            if(gl_VertexID > 1)
            vs_out.color = vec4(1.0, 0.0, 0.0, 1.0);
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
    const char* tesselationEvaluationShaderSource =
        R"(
            layout (triangles, equal_spacing, cw) in;

            void main(void)
            {
            gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position +
            gl_TessCoord.y * gl_in[1].gl_Position +
            gl_TessCoord.z * gl_in[2].gl_Position);
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
            color = fs_in.color;
        })";

    GLFWOpenGLModule* glfwOpenGLModule;
};

#endif // TESTGRAPHICSWORKER_H
