#include "GLFWOpenGLModule.h"

namespace engine {
namespace modules {
    GLFWOpenGLModule::GLFWOpenGLModule(Core* core, unsigned windowWidth, unsigned windowHeight, std::string name)
        : Module(core, name)
        , windowWidth(windowWidth)
        , windowHeight(windowHeight)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(windowWidth, windowHeight, "title", nullptr, nullptr);
        if (window == NULL) {
            // TODO: change for any type of exception
            throw std::exception();
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, windowSizeChanged);
    }
    GLFWOpenGLModule::~GLFWOpenGLModule()
    {
        glfwTerminate();
    }

    void GLFWOpenGLModule::windowSizeChanged(GLFWwindow* window, int width, int height)
    {
    }
}
}
