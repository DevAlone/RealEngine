#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool {
public:
    ThreadPool(size_t threads)
        : _isStopped(false)
    {
        for (size_t i = 0; i < threads; i++) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(this->mutex);

                        this->condition.wait(lock, [this] {
                            return this->_isStopped || !this->tasks.empty();
                        });
                        if (this->_isStopped && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }
                    task();
                    //                    {
                    //                        std::unique_lock<std::mutex> lock(this->mutex);
                    //                    }
                }
            });
        }
    }
    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(mutex);
            _isStopped = true;
        }
        condition.notify_all();
        for (std::thread& worker : workers) {
            worker.join();
        }
    }
    template <typename F, typename... Args>
    std::future<typename std::result_of<F(Args...)>::type> enqueue(F&& f, Args&&... args)
    {
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));

        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(mutex);

            if (_isStopped)
                throw std::runtime_error("enqueue on stopped pool");

            tasks.emplace([task]() { (*task)(); });
        }
        condition.notify_one();
        return res;
    }
    void stop()
    {
        {
            std::unique_lock<std::mutex> lock(mutex);
            _isStopped = true;
        }
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mutex;
    std::condition_variable condition;
    bool _isStopped;
};
