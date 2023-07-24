#include "ReadBlockTask.h"

using namespace pscloud;

int main()
{
    ReadBlockTask task1("bindex1");
    ReadBlockTask task2("bindex2");

    ThreadExecutor<ReadBlockTask> exec;
    exec.addTask(&task1);
    exec.addTask(&task2);


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

#if 0
    class Abc{};
    Abc a;
    ThreadExecutor<Abc> exec2;
    exec2.addTask(&a);
    exec2.run();
#endif

    return 0;
}
