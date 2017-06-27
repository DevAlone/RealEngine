/*
Copyright 2017 Sergey Zakharov
	
Licensed under the Apache License, Version 2.0 (the License);
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0
   
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an AS IS BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Core.h"

namespace engine {
Core::Core()
{
    hardware_threads = std::thread::hardware_concurrency();
    if (hardware_threads < 1)
        // TODO: change to own exception class
        throw std::runtime_error("unable to determine hardware threads count");

    std::cout << "hardware_threads is " << hardware_threads << std::endl;

    beforeGraphicsWorkersThreadPool = std::make_unique<ThreadPool>(hardware_threads);
    independentWorkersThreadPool = std::make_unique<ThreadPool>(hardware_threads);
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
    worker->previousHandlingTime = getTimePoint();
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
    graphicsWorker->previousHandlingTime = getTimePoint();
    graphicsWorkers.push_back(graphicsWorker);
}

void Core::registerGraphicsWorkers(std::vector<std::shared_ptr<GraphicsWorker>>& graphicsWorkers)
{
    for (auto& graphicsWorker : graphicsWorkers)
        registerGraphicsWorker(graphicsWorker);
}

int Core::exec()
{
    // set previous handling time for except problems with big dt on first start
    for (auto& worker : workers)
        worker->previousHandlingTime = getTimePoint();
    for (auto& graphicsWorker : graphicsWorkers)
        graphicsWorker->previousHandlingTime = getTimePoint();

    independentWorkersHandlerThread = std::unique_ptr<std::thread>(new std::thread(independentWorkersHandler, this));
    // TODO: finish it
    while (_isAlive) {

        // TODO: убрать расход ресурсов на выделение памяти и прочее
        // parallel processing
        std::vector<std::future<void>> tasks;
        for (auto& worker : beforeGraphicsWorkers) {
            tasks.push_back(beforeGraphicsWorkersThreadPool->enqueue(handleWorker, this, worker.get()));
        }

        // wait for threads finishing
        for (auto& task : tasks)
            task.wait();

        // sequential processing
        for (auto& worker : beforeGraphicsSynchronizedWorkers) {
            handleWorker(this, worker.get());
        }

        // graphics
        // TODO: предусмотреть возможность параллельной обработки graphicsWorker'ов
        for (auto& graphicsWorker : graphicsWorkers) {
            handleWorker(this, graphicsWorker.get());
        }

        // TODO: add syncronization with workers add functions here
    }

    return 0;
}

void Core::independentWorkersHandler(Core* core)
{
    // TODO: finish it
    while (core->_isAlive) {
        // TODO: optimize this shit
        // parallel processing
        std::vector<std::future<void>> tasks;
        for (auto& worker : core->independentWorkers) {
            tasks.push_back(core->independentWorkersThreadPool->enqueue(handleWorker, core, worker.get()));
        }
        // waiting for finising
        for (auto& task : tasks)
            task.wait();

        // sequential processing
        for (auto& worker : core->independentSynchronizedWorkers) {
            handleWorker(core, worker.get());
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

void Core::stop()
{
    _isAlive = false;
}

std::chrono::time_point<std::chrono::high_resolution_clock> Core::getTimePoint()
{
    return std::chrono::high_resolution_clock::now();
}

void Core::handleWorker(Core* core, AbstractWorker* worker)
{
    auto now = core->getTimePoint();
    auto dt = std::chrono::duration_cast<std::chrono::microseconds>(now - worker->previousHandlingTime).count();
    if (dt < worker->period)
        return;
    worker->handle(dt);
    worker->previousHandlingTime = now;
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
