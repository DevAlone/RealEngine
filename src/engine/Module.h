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

#pragma once

#include "forwards.h"

#include <memory>
#include <string>
#include <vector>

namespace engine {
class Module {
public:
    Module(Core* core, std::string name = "");
    virtual ~Module();

    std::vector<std::shared_ptr<Worker> >& getWorkers();
    void addWorker(std::shared_ptr<Worker> worker);
    std::vector<std::shared_ptr<GraphicsWorker> >& getGraphicsWorkers();
    void addGraphicsWorker(std::shared_ptr<GraphicsWorker> graphicsWorker);

protected:
    Core* core;
    std::string name;
    std::vector<std::shared_ptr<Worker> > workers;
    std::vector<std::shared_ptr<GraphicsWorker> > graphicsWorkers;
};
}
