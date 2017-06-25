#include "AbstractWorker.h"

namespace engine {

AbstractWorker::~AbstractWorker()
{
}

AbstractWorker::AbstractWorker(Core* core, Module* module, const std::string& name)
    : core(core)
    , module(module)
    , name(name)
{
}

const std::string& AbstractWorker::getName() const
{
    return name;
}
}
