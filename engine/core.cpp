#include "core.h"

namespace engine {
Core::Core()
{
    hardware_threads = std::thread::hardware_concurrency();
    if (hardware_threads < 1)
        // TODO: change to own exception class
        throw std::runtime_error("unable to determine hardware threads count");

    std::cout << "hardware_threads is " << hardware_threads << std::endl;

    //    modulesHandlerThread = std::unique_ptr<std::thread>(new std::thread(modulesHandler, this));
}

Core::~Core()
{
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
        throw exceptions::UnableToDetermineWorkerType(worker->getType());
        break;
    }
    // TODO: если worker не добавился, удалить из общего списка
}

void Core::registerWorkers(std::vector<std::shared_ptr<Worker> >& workers)
{
    for (auto worker : workers) {
        registerWorker(worker);
    }
}

#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif

int Core::exec()
{
    // основной цикл приложения
    // здесь планировщик
    std::cout << "exec" << std::endl;
    while (true /* TODO: || something */) {

#ifdef LINUX
        usleep(1 * 1000);
#endif
#ifdef WINDOWS
        Sleep(1);
#endif
    }

    return 0;
}

void Core::gameLoop()
{
    // TODO: finish it
    while (true /* TODO: addSomeCondition */) {
        for (auto& worker : beforeGraphicsWorkers) {
            // параллельная обработка
        }
        // ожидаение завершения
        for (auto& worker : beforeGraphicsSynchronizedWorkers) {
            // последовательная обработка
            // синхронизировать с independentSynchronizedWorkers
        }
        // графика
    }
}

void Core::independentWorkersHandler()
{
    // TODO: finish it
    while (true /* TODO: addSomeCondition */) {
        for (auto& worker : independentWorkers) {
            // параллельная обработка
        }
        // ожидаение завершения
        for (auto& worker : independentSynchronizedWorkers) {
            // последовательная обработка
        }
    }
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
