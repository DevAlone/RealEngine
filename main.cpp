#include <iostream>
#include <memory>

#include <engine/core.h>

using namespace std;

int main(int argc, char* argv[])
{
    // TODO: add logger

    engine::Core core;

    //    core.addModule(
    //        std::unique_ptr<engine::TestModule>(new engine::TestModule));

    return core.exec();
}
