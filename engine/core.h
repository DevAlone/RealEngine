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

#include "engine/graphics_modules/graphicsmodules.h"
#include "engine/graphics_workers/graphicsworkers.h"

namespace engine {
/* forward declarations */
namespace exceptions {
    class UnableToDetermineWorkerType;
}
class GraphicsWorker;
class GraphicsModule;
/* /forward declarations */

class Core {
public:
    Core();
    virtual ~Core();

    void addModule(std::shared_ptr<Module> module);
    // module removes with its workers
    void removeModulesByName(const std::string* name) = delete;
    //    void removeLastModule() = delete;

    void registerWorker(std::shared_ptr<Worker> worker);
    void registerWorkers(std::vector<std::shared_ptr<Worker> >& workers);
    void unregisterWorkersByName(const std::string* name) = delete;

    void addGraphicsModule(std::shared_ptr<GraphicsModule> module);
    void removeGraphicsModulesByName(const std::string* name) = delete;

    void registerGraphicsWorker(std::shared_ptr<GraphicsWorker> graphicsWorker);
    void registerGraphicsWorkers(std::vector<std::shared_ptr<GraphicsWorker> >& graphicsWorkers);
    void unregisterGraphicsWorkersByName(const std::string* name) = delete;

    int exec();
    static void gameLoop(Core* core);
    static void independentWorkersHandler(Core* core);

private:
    unsigned hardware_threads;

    //
    //    std::unique_ptr<std::thread> workersHandlerThread;
    std::unique_ptr<std::thread> gameLoopThread;
    std::unique_ptr<std::thread> independentWorkersHandlerThread;
    struct WorkerWrapper {
        std::shared_ptr<Worker> worker;
        std::chrono::time_point<std::chrono::high_resolution_clock> previousHandleTime;
    };

    std::vector<std::shared_ptr<Module> > modules;
    std::vector<std::shared_ptr<GraphicsModule> > graphicsModules;

    std::vector<std::shared_ptr<Worker> > workers;
    std::vector<std::shared_ptr<Worker> > beforeGraphicsWorkers;
    std::vector<std::shared_ptr<Worker> > beforeGraphicsSynchronizedWorkers;
    std::vector<std::shared_ptr<Worker> > independentWorkers;
    std::vector<std::shared_ptr<Worker> > independentSynchronizedWorkers;

    std::vector<std::shared_ptr<GraphicsWorker> > graphicsWorkers;
};
}

#endif // CORE_H
