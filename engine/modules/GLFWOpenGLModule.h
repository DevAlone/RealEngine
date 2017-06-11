#pragma once

#include "forwards.h"

#include <engine/Module.h>

#include <GLFW/glfw3.h>

#include <iostream>

namespace engine {
namespace modules {
    class GLFWOpenGLModule : public Module {
    public:
        GLFWOpenGLModule(Core* core, unsigned windowWidth, unsigned windowHeight, std::string name = "");
        virtual ~GLFWOpenGLModule();

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
