#include "Core.h"

namespace engine {
Core::Core()
{
    hardware_threads = std::thread::hardware_concurrency();
    if (hardware_threads < 1)
        // TODO: change to own exception class
        throw std::runtime_error("unable to determine hardware threads count");

    std::cout << "hardware_threads is " << hardware_threads << std::endl;

    independentWorkersHandlerThread = std::unique_ptr<std::thread>(new std::thread(independentWorkersHandler, this));
    //    beforeGraphicsWorkersThreadPool = std::make_unique<ThreadPool>(hardware_threads);
}

Core::~Core()
{
    independentWorkersHandlerThread->join();
}

void Core::addModule(std::shared_ptr<Module> module)
{
    modules.push_back(module);
}

void Core::registerWorker(std::shared_ptr<Worker> worker)
{
    workers.push_back(worker);

    switch (worker->getType()) {
    case WORKER_TYPE::BEFORE_GRAPHICS:
        if (worker->isSynchronized())
            beforeGraphicsSynchronizedWorkers.push_back(worker);
        else
            beforeGraphicsWorkers.push_back(worker);
        break;
    case WORKER_TYPE::INDEPENDENT:
        if (worker->isSynchronized())
            independentSynchronizedWorkers.push_back(worker);
        else
            independentWorkers.push_back(worker);
        break;
    default:
        // TODO: add normal exception types
        throw exceptions::UnableToDetermineWorkerType(worker.get());
        break;
    }
}

void Core::registerWorkers(std::vector<std::shared_ptr<Worker>>& workers)
{
    for (auto worker : workers) {
        registerWorker(worker);
    }
}
void Core::registerGraphicsWorker(std::shared_ptr<GraphicsWorker> graphicsWorker)
{
    graphicsWorkers.push_back(graphicsWorker);
}

void Core::registerGraphicsWorkers(std::vector<std::shared_ptr<GraphicsWorker>>& graphicsWorkers)
{
    for (auto& graphicsWorker : graphicsWorkers)
        registerGraphicsWorker(graphicsWorker);
}

int Core::exec()
{
    // TODO: finish it
    while (_isAlive) {

        {
            // TODO: убрать расход ресурсов на выделение памяти и прочее
            std::vector<std::future<void>> tasks;
            for (auto& worker : beforeGraphicsWorkers) {
                tasks.push_back(beforeGraphicsWorkersThreadPool->enqueue(
                    [this, worker] {
                        auto now = getTimePoint();
                        auto dt = std::chrono::duration_cast<std::chrono::microseconds>(now - worker->previousHandlingTime).count();
                        worker->handle(dt);
                        worker->previousHandlingTime = now;
                    }));
            }

            for (auto& task : tasks) {
                task.wait();
            }
        }

        // ожидаение завершения
        for (auto& worker : beforeGraphicsSynchronizedWorkers) {
            auto now = getTimePoint();
            auto dt = std::chrono::duration_cast<std::chrono::microseconds>(now - worker->previousHandlingTime).count();
            worker->handle(dt);
            worker->previousHandlingTime = now;

            // последовательная обработка
            // синхронизировать с independentSynchronizedWorkers?
        }
        // графика
        // TODO: предусмотреть возможность параллельной обработки graphicsWorker'ов
        for (auto& graphicsWorker : graphicsWorkers) {
            auto now = getTimePoint();
            auto dt = std::chrono::duration_cast<std::chrono::microseconds>(now - graphicsWorker->previousHandlingTime).count();
            graphicsWorker->draw(dt);
            graphicsWorker->previousHandlingTime = now;
        }
    }

    independentWorkersHandlerThread->join();

    return 0;
}

void Core::gameLoop(Core* core)
{
}

void Core::independentWorkersHandler(Core* core)
{
    // TODO: finish it
    while (core->_isAlive) {
        for (auto& worker : core->independentWorkers) {
            // параллельная обработка
        }
        // ожидаение завершения
        for (auto& worker : core->independentSynchronizedWorkers) {
            // последовательная обработка
        }
    }
}

bool Core::isPaused() const
{
    return _isPaused;
}

void Core::setPausedState(bool value)
{
    _isPaused = value;
    pausedStateChanged(_isPaused);
}

bool Core::isAlive() const
{
    return _isAlive;
}

std::chrono::time_point<std::chrono::high_resolution_clock> Core::getTimePoint()
{
    return std::chrono::high_resolution_clock::now();
}

//void Core::modulesHandler(Core* core)
//{
//    while (true) {
//        for (auto& moduleWrapper : core->modules) {
//            auto now = std::chrono::high_resolution_clock::now();
//            auto dt = std::chrono::duration_cast<std::chrono::microseconds>(now - moduleWrapper.previousHandleTime);
//            moduleWrapper.previousHandleTime = now;
//            moduleWrapper.module->doIt(dt.count());
//        }
//    }
//}
}
