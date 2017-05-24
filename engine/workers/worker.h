#ifndef WORKER_H
#define WORKER_H

#include <engine/core.h>

namespace engine {
/* forward declarations */
class Core;
class Module;
/* /forward declarations */

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
};
}

#endif // WORKER_H
