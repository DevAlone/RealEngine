#pragma once
#include "forwards.h"

#include <chrono>
#include <string>

namespace engine {
class GraphicsWorker {
    friend class Core;

public:
    GraphicsWorker(Core* core, Module* module, std::string name = "");

    virtual void draw(unsigned microseconds) = 0;

protected:
    Core* core;
    Module* module;
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> previousHandlingTime;

private:
};
}
