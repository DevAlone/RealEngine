#include "GraphicsWorker.h"

namespace engine {
GraphicsWorker::GraphicsWorker(Core* core, Module *module, std::string name)
    : core(core)
    , module(module)
    , name(name)
{
}
}
