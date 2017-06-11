#include "TestGraphicsWorker.h"

#include <iostream>

TestGraphicsWorker::TestGraphicsWorker(engine::Core* core, engine::Module* module, std::string name)
    : GraphicsWorker(core, module, name)
{
    glfwOpenGLModule = dynamic_cast<engine::modules::GLFWOpenGLModule*>(module);
    if (!glfwOpenGLModule)
        // TODO: todo
        throw std::exception();

    int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderId, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShaderId);
    int isSuccess;
    char infoLog[512];
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &isSuccess);
    if (!isSuccess) {
        glGetShaderInfoLog(vertexShaderId, 512, nullptr, infoLog);
        std::cerr << "error compiling shader 1" << infoLog << std::endl;
        // TODO: make exceptions
        throw std::exception();
    }

    int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderId, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShaderId);
    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &isSuccess);
    if (!isSuccess) {
        glGetShaderInfoLog(vertexShaderId, 512, nullptr, infoLog);
        std::cerr << "error compiling shader 2" << infoLog << std::endl;
        // TODO: make exceptions
        throw std::exception();
    }

    shaderProgramId = glCreateProgram();
    glAttachShader(shaderProgramId, vertexShaderId);
    glAttachShader(shaderProgramId, fragmentShaderId);
    glLinkProgram(shaderProgramId);

    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &isSuccess);
    if (!isSuccess) {
        glGetProgramInfoLog(shaderProgramId, 512, nullptr, infoLog);
        std::cout << "error program linking" << infoLog << std::endl;
        throw std::exception();
    }
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f

    };

    glGenVertexArrays(1, &vaoId);
    glGenBuffers(1, &vboId);
    glBindVertexArray(vaoId);

    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

TestGraphicsWorker::~TestGraphicsWorker()
{
    glDeleteVertexArrays(1, &vaoId);
    glDeleteBuffers(1, &vboId);
}

void TestGraphicsWorker::draw(unsigned microseconds)
{

    glfwPollEvents(); //TODO: вынести в другой worker

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgramId);
    glBindVertexArray(vaoId);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    auto windowId = glfwOpenGLModule->getWindow();
    glfwSwapBuffers(windowId);
}
