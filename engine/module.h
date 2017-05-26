#ifndef MODULE_H
#define MODULE_H

#include <memory>

#include "engine.i"

namespace engine {
class Module {
public:
    Module(Core* core);
    virtual ~Module();

    std::vector<std::shared_ptr<Worker> >& getWorkers();

private:
    Core* core;
    std::vector<std::shared_ptr<Worker> > workers;
};
}

#endif // MODULE_H
