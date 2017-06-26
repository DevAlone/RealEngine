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

#include <chrono>
#include <string>

namespace engine {
// TODO: Добавить период обработки или приоритет или что-нибудь подобное
class AbstractWorker {
    friend class Core;

public:
    AbstractWorker(Core* core, Module* module, const std::string& name);
    virtual ~AbstractWorker() = 0;

    const std::string& getName() const;

protected:
    Core* core;
    Module* module;
    const std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> previousHandlingTime;
};
}
