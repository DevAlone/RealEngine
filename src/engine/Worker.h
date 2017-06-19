#pragma once

#include "forwards.h"
#include "includes.h"

namespace engine {
enum class WORKER_TYPE {
    BEFORE_GRAPHICS,
    INDEPENDENT,
};

// TODO: Добавить период обработки или приоритет или что-нибудь подобное
class Worker {
public:
    Worker(Core* core, Module* module, WORKER_TYPE type, bool synchronized, std::string name);
    virtual ~Worker();

    virtual void doIt(unsigned microseconds) = 0;

    WORKER_TYPE getType() const;

    bool isSynchronized() const;

private:
    Core* core;
    Module* module;
    const WORKER_TYPE type;
    const bool synchronized;
    std::string name;
    int testd; //TODO: delete it
};
}
