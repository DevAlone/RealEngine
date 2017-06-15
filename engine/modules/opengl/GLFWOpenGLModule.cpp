#include "GLFWOpenGLModule.h"

namespace engine {
namespace modules {
    namespace opengl {
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

            glewExperimental = GL_TRUE;
            if (glewInit() != GLEW_OK) {
                // TODO: make normal exception
                throw std::exception();
            }

            glfwSetFramebufferSizeCallback(window, framebufferSizeChangedCallback);
        }
        GLFWOpenGLModule::~GLFWOpenGLModule()
        {
            glfwTerminate();
        }

        void GLFWOpenGLModule::framebufferSizeChangedCallback(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        GLFWwindow* GLFWOpenGLModule::getWindow() const
        {
            return window;
        }

        //    void GLFWOpenGLModule::processInput(GLFWwindow* window)
        //    {
        //        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        //            glfwSetWindowShouldClose(window, true);
        //            // TODO: send exit signal to core
        //            exit(0);
        //        }
        //    }
    }
}
}
