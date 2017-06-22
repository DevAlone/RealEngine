#pragma once

#include "forwards.h"
#include "includes.h"

#include <chrono>

namespace engine {
enum class WORKER_TYPE {
    BEFORE_GRAPHICS,
    INDEPENDENT,
};

// TODO: Добавить период обработки или приоритет или что-нибудь подобное
class Worker {
    friend class Core;

public:
    Worker(Core* core, Module* module, WORKER_TYPE type = WORKER_TYPE::BEFORE_GRAPHICS, bool synchronized = false, std::string name = "");
    virtual ~Worker();

    virtual void handle(unsigned microseconds) = 0;

    WORKER_TYPE getType() const;

    bool isSynchronized() const;

protected:
    Core* core;
    Module* module;
    const WORKER_TYPE type;
    const bool synchronized;
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> previousHandlingTime;
};
}
