#include <iostream>
#include <random>

#include "ReadBlockTask.h"

int main(int argc, char *argv[])
{
    std::vector<ReadBlockTask *> taskVec;
    for (auto i = 0; i < 10; ++i)
    {
        taskVec.push_back(new ReadBlockTask("bindex" + itos(i + 1)));
    }

    ThreadExecutor<ReadBlockTask> exec(3);

    for (auto &t : taskVec)
    {
        exec.addTask(t);
    }

    if (auto ret = exec.run(); ret != 0)
    {
        return ret;
    }

    auto tasks = exec.getTask();

    for (auto t : tasks)
    {
        auto datas = t->getData();
        for (auto d : datas)
        {
            d.print();
        }
    }

    for (auto &t : taskVec)
    {
        delete t;
    }

    exec.shutdown();
    return 0;
}