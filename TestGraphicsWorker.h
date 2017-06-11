#ifndef TESTGRAPHICSWORKER_H
#define TESTGRAPHICSWORKER_H

#include "engine/includes.h"

class TestGraphicsWorker : public engine::GraphicsWorker {
public:
    TestGraphicsWorker(engine::Core* core, engine::Module* module, std::string name = "test graphics worker");

    virtual void draw(unsigned microseconds);
};

#endif // TESTGRAPHICSWORKER_H
