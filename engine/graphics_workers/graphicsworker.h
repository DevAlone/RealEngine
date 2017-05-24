#ifndef GRAPHICSWORKER_H
#define GRAPHICSWORKER_H

#include "engine/core.h"
#include "engine/graphics_modules/graphicsmodules.h"

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

#endif // GRAPHICSWORKER_H
