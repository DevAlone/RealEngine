/*
Copyright 2017 Sergey Zakharov
	
Licensed under the Apache License, Version 2.0 (the License);
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0
   
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an AS IS BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

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

    virtual void handle(unsigned microseconds);

private:
    engine::modules::opengl::GLSLProgram shaderProgram;
    GLuint vaoId;
    const char* vertexShaderSource =
        R"(
//            #extension ARB_geometry_shader4 : require

//            layout (location = 0) in vec4 color;

            out VS_OUT
            {
                vec4 color;
            } vs_out;

            void main()
            {
                const vec4 vertices[3] = vec4[3](
        vec4(-1, -1, 0.5, 1.0),
        vec4(1, -1, 0.5, 1.0),
        vec4(0, 0, 0.5, 1.0)
        );
            const vec4 colors[] = vec4[3](vec4(1.0, 0.0, 0.0,1.0), vec4(0.0, 1.0, 0.0,1.0), vec4(0.0, 0.0, 1.0,1.0));


                gl_Position = vertices[gl_VertexID];

                vs_out.color = colors[gl_VertexID];;
            })";
    const char* tesselationControlShaderSource =
        R"(layout (vertices = 3) out;

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

    const char* geometryShaderSource =
        R"(layout (triangles) in;
            layout (points, max_vertices = 3) out;

        out VS_OUT
        {
            vec4 color;
        } gs_out;
            void main(void)
            {
            int i;
            for(i = 0; i < gl_in.length(); i++) {
            gl_Position = gl_in[i].gl_Position;
            EmitVertex();
            }
    //            EndPrimitive();
            gs_out.color = vec4(1.0, 0, 0, 1.0);
            }
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
//            color = fs_in.color;
//            color = vec4(
//        (int(gl_FragCoord.x) % 100)/100.0, //sin(gl_FragCoord.x * 0.25) * 0.5 + 0.5,
//        0, //cos(gl_FragCoord.y * 0.25) * 0.5 + 0.5,
//        sin(gl_FragCoord.x * 0.15) / cos(gl_FragCoord.y * 0.25), 1.0
//        );
//            color = vec4(1.0, 0, 0, 1.0);
        })";

    GLFWOpenGLModule* glfwOpenGLModule;
};

#endif // TESTGRAPHICSWORKER_H
