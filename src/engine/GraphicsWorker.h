#pragma once

#include "forwards.h"

#include "AbstractWorker.h"

#include <chrono>
#include <string>

namespace engine {
class GraphicsWorker : public AbstractWorker {
public:
    GraphicsWorker(Core* core, Module* module, const std::string& name = "");

    virtual void draw(unsigned microseconds) = 0;

protected:
private:
};
}
