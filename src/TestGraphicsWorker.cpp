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

#include "TestGraphicsWorker.h"

#include <chrono>
#include <cmath>
#include <iostream>

#include <engine/modules/opengl/includes.h>

using namespace engine::modules::opengl;

TestGraphicsWorker::TestGraphicsWorker(engine::Core* core, engine::Module* module, std::string name)
    : GraphicsWorker(core, module, name)
{
    glfwOpenGLModule = dynamic_cast<GLFWOpenGLModule*>(module);
    if (!glfwOpenGLModule)
        // TODO: todo
        throw std::exception();

    glfwMakeContextCurrent(glfwOpenGLModule->getWindow());

    auto openGLVersion = GLSL_SHADER_VERSION::GL_330;

    auto vertexShader = std::make_shared<GLSLVertexShader>(vertexShaderSource, openGLVersion);
    vertexShader->init();
    vertexShader->compile();

    auto fragmentShader = std::make_shared<GLSLFragmentShader>(fragmentShaderSource, openGLVersion);
    fragmentShader->init();
    fragmentShader->compile();

    auto geometryShader = std::make_shared<GLSLGeometryShader>(geometryShaderSource, openGLVersion);
    geometryShader->init();
    geometryShader->compile();

    //    auto tesselationControlShader = std::make_shared<GLSLTesselationControlShader>(tesselationControlShaderSource, openGLVersion);
    //    tesselationControlShader->init();
    //    tesselationControlShader->compile();

    //    auto tesselationEvaluationShader = std::make_shared<GLSLTesselationEvaluationShader>(tesselationEvaluationShaderSource, openGLVersion);
    //    tesselationEvaluationShader->init();
    //    tesselationEvaluationShader->compile();

    shaderProgram.init();
    shaderProgram.attachShader(vertexShader);
    shaderProgram.attachShader(fragmentShader);
    //    shaderProgram.attachShader(tesselationControlShader);
    //    shaderProgram.attachShader(tesselationEvaluationShader);
    //    shaderProgram.attachShader(geometryShader);
    shaderProgram.link();

    //

    //    int tesselationControlShaderId = glCreateShader(GL_TESS_CONTROL_SHADER);
    //    glShaderSource(tesselationControlShaderId, 1, &tesselationControlShaderSource, nullptr);
    //    glCompileShader(tesselationControlShaderId);

    //    glGetShaderiv(tesselationControlShaderId, GL_COMPILE_STATUS, &isSuccess);
    //    if (!isSuccess) {
    //        glGetShaderInfoLog(tesselationControlShaderId, 512, nullptr, infoLog);
    //        std::cerr << "error compiling shader 2" << infoLog << std::endl;
    //        // TODO: make exceptions
    //        throw std::exception();
    //    }

    //

    //    float vertices[] = {
    //        -0.5f, -0.5f, 0.0f,
    //        0.5f, -0.5f, 0.0f,
    //        0.0f, 0.5f, 0.0f

    //    };

    //    glGenVertexArrays(1, &vaoId);
    //    glGenBuffers(1, &vboId);
    //    glBindVertexArray(vaoId);

    //    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    //    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //    glEnableVertexAttribArray(0);

    //    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //    glBindVertexArray(0);
    //    glCreateVertexArrays(1, &vaoId);
    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);
}

TestGraphicsWorker::~TestGraphicsWorker()
{
    glDeleteVertexArrays(1, &vaoId);
    //    glDeleteBuffers(1, &vboId);
}

void TestGraphicsWorker::handle(unsigned microseconds)
{
    //    std::cout << "dt: " << microseconds << std::endl;
    auto windowId = glfwOpenGLModule->getWindow();
    glfwMakeContextCurrent(windowId);

    glfwPollEvents(); //TODO: вынести в другой worker

    std::chrono::milliseconds currTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch());
    auto currentTime = currTime.count() / 100;

    //    const GLfloat color[] = { (float)sin(currentTime) * 0.5f + 0.5f,
    //        (float)cos(currentTime) * 0.5f + 0.5f,
    //        0.0, 1.0f };
    //    const GLfloat color[] = { 0.1, 0.1, 0.1 };
    //    glClearBufferfv(GL_COLOR, 0, color);
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_CULL_FACE);

    glUseProgram(shaderProgram.getId());

    glBindVertexArray(vaoId);

    glVertexAttrib4f(0,
        0,
        1,
        0.0,
        1.0);

    //    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //    glPointSize(25);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(windowId);
}
