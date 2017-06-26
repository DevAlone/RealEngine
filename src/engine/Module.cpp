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


#include "Module.h"

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
