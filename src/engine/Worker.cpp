#include "Worker.h"

namespace engine {

Worker::Worker(Core* core, Module* module, WORKER_TYPE type, bool synchronized, const std::string& name)
    : AbstractWorker(core, module, name)
    , type(type)
    , synchronized(synchronized)
{
}

Worker::Worker(std::function<void(Worker*, unsigned microseconds)> function, Core* core, Module* module, WORKER_TYPE type, bool synchronized, const std::string& name)
    : AbstractWorker(core, module, name)
    , type(type)
    , synchronized(synchronized)
    , function(function)
{
}

Worker::~Worker()
{
}

void Worker::handle(unsigned microseconds)
{
    if (function)
        function(this, microseconds);
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
