#include "worker.h"

#include <engine/modules/modules.h>

namespace engine {

Worker::Worker(Core* core, Module* module, WORKER_TYPE type, bool synchronized)
    : core(core)
    , module(module)
    , type(type)
    , synchronized(synchronized)
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
