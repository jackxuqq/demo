#pragma once

#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

#include "SafeQueue.h"

class ThreadTask
{
public:
    ThreadTask()
    {
    }

    virtual ~ThreadTask()
    {
    }

    virtual int run() = 0;

    // virtual int getResult() = 0;
};

template <typename T>
class ThreadExecutor
{
private:
    class ThreadWorker
    {
    private:
        int m_id;
        ThreadExecutor *m_pool;

    public:
        ThreadWorker(ThreadExecutor *pool, const int id)
            : m_pool(pool), m_id(id)
        {
        }

        void operator()()
        {
            std::function<void()> func;
            bool dequeued;
            while (!m_pool->m_shutdown)
            {
                {
                    std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);
                    if (m_pool->m_queue.empty())
                    {
                        m_pool->m_conditional_lock.wait(lock);
                    }
                    dequeued = m_pool->m_queue.dequeue(func);
                }
                if (dequeued)
                {
                    func();
                }
            }
        }
    };
    bool m_shutdown;
    SafeQueue<std::function<void()>> m_queue;
    std::vector<std::thread> m_threads;
    std::mutex m_conditional_mutex;
    std::condition_variable m_conditional_lock;

    std::vector<T *> m_tasks;

public:
    ThreadExecutor(const int n_threads)
        : m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false)
    {
        init();
    }

    ~ThreadExecutor()
    {
        shutdown();
    }

    ThreadExecutor(const ThreadExecutor &) = delete;
    ThreadExecutor(ThreadExecutor &&) = delete;

    ThreadExecutor &operator=(const ThreadExecutor &) = delete;
    ThreadExecutor &operator=(ThreadExecutor &&) = delete;

    // Waits until threads finish their current task and shutdowns the pool
    void shutdown()
    {
        if (!m_shutdown)
        {
            m_shutdown = true;
            m_conditional_lock.notify_all();

            for (int i = 0; i < m_threads.size(); ++i)
            {
                if (m_threads[i].joinable())
                {
                    m_threads[i].join();
                }
            }
        }
    }

    void addTask(T *task)
    {
        m_tasks.push_back(task);
    }

    const std::vector<T *> &getTask() const
    {
        return m_tasks;
    }

    int run()
    {
        std::vector<std::future<int>> futures;

        // all task in queue
        for (auto task : m_tasks)
        {
            auto lambda = [task]() -> int
            {
                return task->run();
            };
            auto taskPtr = std::make_shared<std::packaged_task<int()>>(lambda);

            std::function<void()> funcWrap = [taskPtr]()
            {
                (*taskPtr)();
            };

            futures.push_back(taskPtr->get_future());
            m_queue.enqueue(funcWrap);
            m_conditional_lock.notify_one();
        }

        // wait exec result
        auto ret = 0;
        for (auto &future : futures)
        {
            auto tmp = future.get();
            if (tmp != 0)
            {
                ret = tmp;
            }
        }

        // all task done
        if (ret != 0)
        {
            return ret;
        }
        return 0;
    }

private:
    // Inits thread pool
    void init()
    {
        for (int i = 0; i < m_threads.size(); ++i)
        {
            m_threads[i] = std::thread(ThreadWorker(this, i));
        }
    }
};
