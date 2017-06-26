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


#include "GLFWOpenGLModule.h"

namespace engine {
namespace modules {
    namespace opengl {
        GLFWOpenGLModule::GLFWOpenGLModule(Core* core, unsigned windowWidth, unsigned windowHeight, std::string name)
            : Module(core, name)
            , windowWidth(windowWidth)
            , windowHeight(windowHeight)
        {
            static int objectsCount = 0;
            objectsCount++;
            //            if (objectsCount > 1)
            //                throw std::exception();

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
