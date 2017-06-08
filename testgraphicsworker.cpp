#include "testgraphicsworker.h"

#include <iostream>

TestGraphicsWorker::TestGraphicsWorker(engine::Core* core, engine::Module* module, std::string name)
    : GraphicsWorker(core, module, name)
{
}

void TestGraphicsWorker::draw(unsigned microseconds)
{
    std::cout << "I'm drawing!";
}
