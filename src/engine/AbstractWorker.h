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
