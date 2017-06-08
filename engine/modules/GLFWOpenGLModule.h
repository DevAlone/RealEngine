#pragma once

#include "forwards.h"

#include <engine/module.h>

#include <GLFW/glfw3.h>

#include <iostream>

namespace engine {
namespace modules {
    class GLFWOpenGLModule : public Module {
    public:
        GLFWOpenGLModule(Core* core, unsigned windowWidth, unsigned windowHeight, std::string name = "");
        virtual ~GLFWOpenGLModule();

    protected:
        static void windowSizeChanged(GLFWwindow* window, int width, int height);

    private:
        GLFWwindow* window;
        unsigned windowWidth;
        unsigned windowHeight;
    };
}
}
