#ifndef GRAPHICSWORKER_H
#define GRAPHICSWORKER_H

#include "engine.i"

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
