#pragma once

#include "forwards.h"

#include <memory>
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
