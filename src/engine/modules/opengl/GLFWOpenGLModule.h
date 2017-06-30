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

#pragma once

#include "forwards.h"

#include <engine/Module.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <iostream>

// TODO: add list(set) of extensions and function to find in that list
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
