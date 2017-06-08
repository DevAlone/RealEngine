#pragma once

#include "forwards.h"

#include <memory>
#include <vector>

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
