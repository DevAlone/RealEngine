#pragma once
#include "forwards.h"

#include <string>

namespace engine {
class GraphicsWorker {
public:
    GraphicsWorker(Core* core, GraphicsModule* module, std::string name = "");

    virtual void draw() = 0;

protected:
    Core* core;
    GraphicsModule* module;
    std::string name;

private:
};
}
