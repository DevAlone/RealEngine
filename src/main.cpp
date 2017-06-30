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

#include "engine/includes.h"

#include "TestGraphicsWorker.h"
#include "engine/modules/opengl/includes.h"

#include <iostream>
#include <memory>

using namespace engine;
using namespace engine::modules::opengl;

class TestWorker : public engine::Worker {
public:
    TestWorker(Core* core, Module* module)
        : engine::Worker(core, module)
    {
    }

    virtual void handle(unsigned microseconds)
    {
        static int i = 0;
        i++;
        std::cout << i << std::endl;
    }
};

int main(int argc, char* argv[])
{

    // TODO: add logger
    // TODO: add framework for tests

    //    std::cout << glGetString(GL_VERSION) << std::endl;
    //    while (true)
    //        ;

    Core core;

    //    auto glfwOpenGLModule = std::make_unique<GLFWOpenGLModule>(&core, 800, 600);
    auto glfwOpenGLModule = ModuleUniquePtr<GLFWOpenGLModule>(new GLFWOpenGLModule(&core, 800, 600));
    auto windowId1 = glfwOpenGLModule->getWindow();

    auto testGraphicsWorker = std::make_shared<TestGraphicsWorker>(&core, glfwOpenGLModule.get());
    glfwOpenGLModule->addGraphicsWorker(testGraphicsWorker);

    core.registerGraphicsWorker(testGraphicsWorker);

    // core.addModule(static_cast<ModuleUniquePtr<GLFWOpenGLModule>&&>(glfwOpenGLModule));
    core.addModule(std::move(glfwOpenGLModule));

    auto lambdaWorker = std::make_shared<Worker>([&core](auto worker, unsigned microseconds) {
        std::cout << microseconds << std::endl;
        auto weak = core.getModule<GLFWOpenGLModule>();
        auto windowId = weak->getWindow();

        std::cout << "windowId is " << windowId << std::endl;
        //        core.stop();
    },
        &core, nullptr); //, WORKER_TYPE::INDEPENDENT);
    core.registerWorker(lambdaWorker);

    lambdaWorker->setPeriod(1000 * 1000);

    auto weak = core.getModule<GLFWOpenGLModule>();
    //    auto weak2 = core.getModule<int>();
    auto windowId2 = weak->getWindow();

    std::cout << "@ id1 = " << windowId1 << ", id2 = " << windowId2 << "; (id1 == id2) is " << (windowId1 == windowId2) << "; " << std::endl;

    //    //    core.getModule<GLFWOpenGLModule>();
    //    if (weak)
    //        std::cout << "aaaaa" << std::endl;

    //    std::cout << windowId1 << std::endl;

    return core.exec();
}
