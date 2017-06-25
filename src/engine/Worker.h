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
