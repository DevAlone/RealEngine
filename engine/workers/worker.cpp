#include "worker.h"

#include <engine/modules/modules.h>

namespace engine {

Worker::Worker(Core* core, Module* module, WORKER_TYPE type, bool synchronized, std::__cxx11::string name)
    : core(core)
    , module(module)
    , type(type)
    , synchronized(synchronized)
    , name(name)
{
}

Worker::~Worker()
{
}

WORKER_TYPE Worker::getType() const
{
    return type;
}

bool Worker::isSynchronized() const
{
    return synchronized;
}
}
