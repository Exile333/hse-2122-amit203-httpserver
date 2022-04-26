#include <types.h>
#include <vector>
#include <thread>>

class ThreadPool{
public:
    ThreadPool(size_t thread_count);
private:
    void WorkRoutine();
    std::vector<std::thread> threads;
    // blocking queue for threads
};