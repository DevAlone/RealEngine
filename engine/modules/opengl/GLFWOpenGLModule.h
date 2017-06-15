#pragma once

#include "forwards.h"

#include <engine/Module.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <iostream>

namespace engine {
namespace modules {
    namespace opengl {
        class GLFWOpenGLModule : public Module {
        public:
            GLFWOpenGLModule(Core* core, unsigned windowWidth, unsigned windowHeight, std::string name = "");
            virtual ~GLFWOpenGLModule();

            GLFWwindow* getWindow() const;

        protected:
            static void framebufferSizeChangedCallback(GLFWwindow* window, int width, int height);
            //        static void processInput(GLFWwindow* window);

        private:
            GLFWwindow* window;
            unsigned windowWidth;
            unsigned windowHeight;
        };
    }
}
}
