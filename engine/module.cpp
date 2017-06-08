#include "module.h"

namespace engine {
Module::Module(Core* core, std::string name)
    : core(core)
    , name(name)
{
}

Module::~Module()
{
}

std::vector<std::shared_ptr<Worker> >& Module::getWorkers()
{
    return workers;
}

void Module::addWorker(std::shared_ptr<Worker> worker)
{
    workers.push_back(worker);
}

std::vector<std::shared_ptr<GraphicsWorker> >& Module::getGraphicsWorkers()
{
    return graphicsWorkers;
}

void Module::addGraphicsWorker(std::shared_ptr<GraphicsWorker> graphicsWorker)
{
    graphicsWorkers.push_back(graphicsWorker);
}
}
