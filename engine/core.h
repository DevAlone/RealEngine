#ifndef CORE_H
#define CORE_H

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include "engine/exceptions/exceptions.h"
#include "engine/modules/modules.h"
#include "engine/workers/workers.h"

namespace engine {
/* forward declarations */
namespace exceptions {
    class UnableToDetermineWorkerType;
}
/* /forward declarations */

class Core {
public:
    Core();
    virtual ~Core();

    void addModule(std::shared_ptr<Module> module);
    // module removes with its workers
    void removeModuleByName(const std::string* name) = delete;
    void removeLastModule() = delete;
    void registerWorker(std::shared_ptr<Worker> worker);
    void registerWorkers(std::vector<std::shared_ptr<Worker> >& workers);

    int exec();
    void gameLoop();
    void independentWorkersHandler();

private:
    unsigned hardware_threads;

    //
    //    std::unique_ptr<std::thread> workersHandlerThread;
    struct WorkerWrapper {
        std::shared_ptr<Worker> worker;
        std::chrono::time_point<std::chrono::high_resolution_clock> previousHandleTime;
    };

    std::vector<std::shared_ptr<Module> > modules;

    std::vector<std::shared_ptr<Worker> > workers;
    std::vector<std::shared_ptr<Worker> > beforeGraphicsWorkers;
    std::vector<std::shared_ptr<Worker> > beforeGraphicsSynchronizedWorkers;
    std::vector<std::shared_ptr<Worker> > independentWorkers;
    std::vector<std::shared_ptr<Worker> > independentSynchronizedWorkers;
};
}

#endif // CORE_H
