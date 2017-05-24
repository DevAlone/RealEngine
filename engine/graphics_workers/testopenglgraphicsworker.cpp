#include "testopenglgraphicsworker.h"

namespace engine {

TestOpenglGraphicsWorker::TestOpenglGraphicsWorker()
    : GraphicsWorker(0, 0)
{
}

void TestOpenglGraphicsWorker::draw()
{
    std::cout << "I'm drawing!" << std::endl;
}
}
