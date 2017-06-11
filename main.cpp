#include <iostream>
#include <memory>

#include "TestGraphicsWorker.h"
#include "engine/includes.h"
#include <engine/modules/includes.h>

using namespace std;

int main(int argc, char* argv[])
{
    //    std::cout << glGetString(GL_VERSION) << std::endl;
    //    while (true)
    //        ;
    // TODO: add logger

    engine::Core core;

    auto glfwOpenGLModule = std::make_shared<engine::modules::GLFWOpenGLModule>(&core, 800, 600);

    auto testGraphicsWorker = std::make_shared<TestGraphicsWorker>(&core, glfwOpenGLModule.get());
    glfwOpenGLModule->addGraphicsWorker(testGraphicsWorker);

    core.registerGraphicsWorker(testGraphicsWorker);

    core.addModule(glfwOpenGLModule);
    //    core.addModule(
    //        std::unique_ptr<engine::TestModule>(new engine::TestModule));

    //    auto openGLTestWorker = std::shared_ptr<engine::TestOpenglGraphicsWorker>(new engine::TestOpenglGraphicsWorker);
    //    core.registerGraphicsWorker(openGLTestWorker);

    return core.exec();
}
