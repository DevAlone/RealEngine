/*
Copyright 2017 Sergey Zakharov
	
Licensed under the Apache License, Version 2.0 (the License);
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0
   
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an AS IS BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/


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
