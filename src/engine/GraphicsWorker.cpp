#include "GraphicsWorker.h"

namespace engine {
GraphicsWorker::GraphicsWorker(Core* core, Module* module, const std::string& name)
    : AbstractWorker(core, module, name)
{
}
}
