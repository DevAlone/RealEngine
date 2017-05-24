#include "graphicsworker.h"

namespace engine {
GraphicsWorker::GraphicsWorker(Core* core, GraphicsModule* module, std::string name)
    : core(core)
    , module(module)
    , name(name)
{
}
}
