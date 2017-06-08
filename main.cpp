#include <iostream>
#include <memory>

#include "engine/includes.h"

using namespace std;

int main(int argc, char* argv[])
{
    // TODO: add logger

    engine::Core core;

    //    core.addModule(
    //        std::unique_ptr<engine::TestModule>(new engine::TestModule));

    //    auto openGLTestWorker = std::shared_ptr<engine::TestOpenglGraphicsWorker>(new engine::TestOpenglGraphicsWorker);
    //    core.registerGraphicsWorker(openGLTestWorker);

    return core.exec();
}
