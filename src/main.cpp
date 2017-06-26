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

    //    auto glfwOpenGLModule = std::make_shared<GLFWOpenGLModule>(&core, 800, 600);
    //    auto testGraphicsWorker = std::make_shared<TestGraphicsWorker>(&core, glfwOpenGLModule.get());
    //    glfwOpenGLModule->addGraphicsWorker(testGraphicsWorker);

    //    core.registerGraphicsWorker(testGraphicsWorker);

    //    core.addModule(glfwOpenGLModule);

    //    core.registerWorker(std::make_shared<Worker>([&core](auto worker) {
    //        std::cout << "I'm lambda worker!" << std::endl;
    //        if (core.isAlive())
    //            std::cout << "core is alive!" << std::endl;
    //    },
    //        &core, nullptr));

    //    core.registerWorker(std::make_shared<Worker>([&core](auto worker, unsigned microseconds) {
    //        static int i = 0;
    //        i++;
    //        std::cout << i << std::endl;
    //    },
    //        &core, nullptr));
    //    core.registerWorker(std::make_shared<TestWorker>(&core, nullptr));

    int i = 0;
    core.registerWorker(std::make_shared<Worker>([&core, &i](auto worker, unsigned microseconds) {
        std::cout << "something" << std::endl;
        i++;
        if (i > 10000000)
            core.stop();
    },
        &core, nullptr));
    core.exec();
    std::cout << "i is " << i << std::endl;
    //    auto testWorker = std::make_shared<TestWorker>(&core, nullptr);
    //    core.registerWorker(testWorker);
    //    core.registerWorker(std::make_shared<TestWorker>(&core, nullptr));
    //    core.registerWorker(std::make_shared<TestWorker>(&core, nullptr));
    //    core.registerWorker(std::make_shared<TestWorker>(&core, nullptr));
    //    core.registerWorker(std::make_shared<TestWorker>(&core, nullptr));
    //    core.registerWorker(std::make_shared<TestWorker>(&core, nullptr));

    return core.exec();
}
