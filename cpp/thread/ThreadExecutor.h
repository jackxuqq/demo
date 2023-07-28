/***************************************************************************************
* @file       ThreadExecutor.h
* @brief      multi-thread executor
* @details
* @author     xuzewei
* @date       2023-07-19
* @version    V1.0
* @copyright  Copyright (c) 2022-2025  Shen Zhen Poisson Software Technology CO.,LTD
**************************************************************************************/
#include <iostream>
#include <thread>
#include <utility>
#include <string>
#include <vector>

namespace pscloud
{

#if 0
    enum class TaskType
    {
        Init = 0,
        ReadTask = 1,
        WriteTask = 2,
    };
#endif

    class ThreadTask
    {
    public:
        ThreadTask()
        {
        }

        virtual ~ThreadTask()
        {
        }

        virtual void run() = 0;

        virtual int getResult() = 0;

#if 0
       TaskType getTaskType()
       {
           return m_taskType;
       }
#endif

    protected:
        //TaskType m_taskType;
    };

    template<typename T>
    class ThreadExecutor final
    {
    public:

        ThreadExecutor()
        {
            static_assert(std::is_base_of<ThreadTask, T>::value, "should be ThreadTask's children");
        }

        ~ThreadExecutor()
        {
            for (auto thread : m_threads)
            {
                delete thread;
            }
        }

        void addTask(T* task)
        {
            m_tasks.push_back(task);
        }

        int run()
        {
            for (auto task : m_tasks)
            {
                auto lambda = [](T* task){
                    task->run();
                };
                auto thread = new std::thread(lambda, task);
                //auto thread = new std::thread(&ThreadTask::run, task);
                m_threads.push_back(thread);

            }

            return wait();
        }

        const std::vector<T*>& getTask() const
        {
            return m_tasks;
        }

    private:
        int wait()
        {
            for (auto thread : m_threads)
            {
                thread->join();
            }

            std::cout << "all task done." << std::endl;

            for (auto task : m_tasks)
            {
                if (auto ret = task->getResult(); ret != 0)
                {
                    std::cout << "same err:" << ret << std::endl;
                    return ret;
                }
            }

            std::cout << "all success." << std::endl;
            return 0;
        }

    private:
        std::vector<T*> m_tasks;
        std::vector<std::thread*> m_threads;
    };

}
