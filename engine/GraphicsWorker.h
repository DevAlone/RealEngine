#pragma once
#include "forwards.h"

#include <string>

namespace engine {
class GraphicsWorker {
public:
    GraphicsWorker(Core* core, Module* module, std::string name = "");

    virtual void draw(unsigned microseconds) = 0;

protected:
    Core* core;
    Module* module;
    std::string name;

private:
};
}
