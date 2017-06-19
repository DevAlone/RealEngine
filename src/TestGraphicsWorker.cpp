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

    auto vertexShader = std::make_shared<GLSLVertexShader>(vertexShaderSource, GLSL_SHADER_VERSION::GL_330);
    vertexShader->init();
    vertexShader->compile();

    auto fragmentShader = std::make_shared<GLSLFragmentShader>(fragmentShaderSource, GLSL_SHADER_VERSION::GL_330);
    fragmentShader->init();
    fragmentShader->compile();

    shaderProgram.init();
    shaderProgram.attachShader(vertexShader);
    shaderProgram.attachShader(fragmentShader);
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
    glCreateVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);
}

TestGraphicsWorker::~TestGraphicsWorker()
{
    glDeleteVertexArrays(1, &vaoId);
    glDeleteBuffers(1, &vboId);
}

void TestGraphicsWorker::draw(unsigned microseconds)
{
    auto windowId = glfwOpenGLModule->getWindow();
    glfwMakeContextCurrent(windowId);

    glfwPollEvents(); //TODO: вынести в другой worker

    //    glClearColor(1.0, 1.0, 1.0, 1.0);
    //    glClear(GL_COLOR_BUFFER_BIT);
    std::chrono::milliseconds currTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch());
    auto currentTime = currTime.count() / 100;

    const GLfloat color[] = { (float)sin(currentTime) * 0.5f + 0.5f,
        (float)cos(currentTime) * 0.5f + 0.5f,
        0.0, 1.0f };
    glClearBufferfv(GL_COLOR, 0, color);

    glUseProgram(shaderProgram.getId());

    const GLfloat offset[4] = { (float)sin(currentTime), 0.2, 0.3, 0 };
    glVertexAttrib4fv(0, offset);
    glVertexAttrib4f(1, 0.0, sin(currentTime) >= 0 ? sin(currentTime) : -sin(currentTime), 0.0, 1.0);

    //    glBindVertexArray(vaoId);
    glPointSize(25);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(windowId);
}
