#include "module.h"

namespace engine {
Module::Module(Core* core)
    : core(core)
{
}

Module::~Module()
{
}

std::vector<std::shared_ptr<Worker> >& Module::getWorkers()
{
    return workers;
}
}
