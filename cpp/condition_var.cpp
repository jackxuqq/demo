#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>


enum class FlowState
{
    Init = 0,
    Trig = 1,
    Process = 2
};

std::mutex m;
std::condition_variable cv;
std::string data;
void worker_thread(FlowState& state)
{
    // 等待直至 main() 发送数据
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [&]{
            if (state == FlowState::Trig)
            {
                return true;
            }
            return false;
    });

    // 等待后，我们占有锁。
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // 发送数据回 main()
    state = FlowState::Process;
    std::cout << "Worker thread signals data processing completed\n";

    // 通知前完成手动解锁，以避免等待线程才被唤醒就阻塞（细节见 notify_one ）
    lk.unlock();
    cv.notify_one();
}

int main()
{
    FlowState state = FlowState::Init;
    std::thread worker(worker_thread, std::ref(state));

    data = "Init data";
    // 发送数据到 worker 线程
    {
        std::lock_guard<std::mutex> lk(m);
        state = FlowState::Trig;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();

    // 等候 worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [&]{
                if (state == FlowState::Process)
                {
                    return true;
                }
                return false;
        });
    }
    std::cout << "Back in main(), data = " << data << '\n';

    worker.join();
}
