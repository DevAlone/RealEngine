#ifndef TESTOPENGLGRAPHICSWORKER_H
#define TESTOPENGLGRAPHICSWORKER_H

#include <iostream>

#include "graphicsworker.h"

namespace engine {
class TestOpenglGraphicsWorker : public GraphicsWorker {
public:
    TestOpenglGraphicsWorker();
    virtual void draw();
};
}

#endif // TESTOPENGLGRAPHICSWORKER_H
