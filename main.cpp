#include <iostream>
#include <memory>

#include "TestGraphicsWorker.h"
#include "engine/includes.h"
#include "engine/modules/opengl/includes.h"

using namespace engine;
using namespace engine::modules::opengl;

using namespace std;

int main(int argc, char* argv[])
{
    // TODO: add logger
    // TODO: add framework for tests

    //    std::cout << glGetString(GL_VERSION) << std::endl;
    //    while (true)
    //        ;

    Core core;

    auto glfwOpenGLModule = std::make_shared<GLFWOpenGLModule>(&core, 800, 600);

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
