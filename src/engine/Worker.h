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
#include "includes.h"

#include <chrono>
#include <functional>

namespace engine {
enum class WORKER_TYPE {
    BEFORE_GRAPHICS,
    INDEPENDENT,
};

// TODO: Добавить период обработки или приоритет или что-нибудь подобное
class Worker : public AbstractWorker {
public:
    Worker(Core* core, Module* module, WORKER_TYPE type = WORKER_TYPE::BEFORE_GRAPHICS, bool synchronized = false, const std::string& name = "");
    Worker(std::function<void(Worker*, unsigned)> function, Core* core, Module* module, WORKER_TYPE type = WORKER_TYPE::BEFORE_GRAPHICS, bool synchronized = false, const std::string& name = "");
    virtual ~Worker();

    virtual void handle(unsigned microseconds);

    WORKER_TYPE getType() const;

    bool isSynchronized() const;

protected:
    const WORKER_TYPE type;
    const bool synchronized;

private:
    std::function<void(Worker*, unsigned)> function;
};
}
