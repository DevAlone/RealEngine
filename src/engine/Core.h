#pragma once

#include "ThreadPool.hpp"
#include "forwards.h"
#include "includes.h"

#include "engine/exceptions/includes.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include <boost/signals2.hpp>

namespace engine {

// TODO: add methods for executing tasks in threads
// TODO: разобраться, почему один worker грузит все 6 ядер
class Core {
public:
    Core();
    virtual ~Core();
    // TODO: change to std::unique_ptr
    void addModule(std::shared_ptr<Module> module);
    // module removes with its workers
    void removeModulesByName(const std::string* name) = delete;
    //    void removeLastModule() = delete;

    void registerWorker(std::shared_ptr<Worker> worker);
    void registerWorkers(std::vector<std::shared_ptr<Worker>>& workers);
    void unregisterWorkersByName(const std::string* name) = delete;

    void registerGraphicsWorker(std::shared_ptr<GraphicsWorker> graphicsWorker);
    void registerGraphicsWorkers(std::vector<std::shared_ptr<GraphicsWorker>>& graphicsWorkers);
    void unregisterGraphicsWorkersByName(const std::string* name) = delete;

    int exec();
    static void independentWorkersHandler(Core* core);

    bool isPaused() const;
    void setPausedState(bool value);
    boost::signals2::signal<void(bool)> pausedStateChanged;

    bool isAlive() const;
    void stop();

private:
    unsigned hardware_threads;
    std::unique_ptr<std::thread> independentWorkersHandlerThread;

    std::vector<std::shared_ptr<Module>> modules;

    std::vector<std::shared_ptr<Worker>> workers;

    std::vector<std::shared_ptr<Worker>> beforeGraphicsWorkers;
    std::vector<std::shared_ptr<Worker>> beforeGraphicsSynchronizedWorkers;
    std::vector<std::shared_ptr<Worker>> independentWorkers;
    std::vector<std::shared_ptr<Worker>> independentSynchronizedWorkers;

    std::vector<std::shared_ptr<GraphicsWorker>> graphicsWorkers;

    std::unique_ptr<ThreadPool> beforeGraphicsWorkersThreadPool;
    std::unique_ptr<ThreadPool> independentWorkersThreadPool;

    bool _isPaused;
    bool _isAlive = true;
    std::chrono::time_point<std::chrono::high_resolution_clock> getTimePoint();
};
}
