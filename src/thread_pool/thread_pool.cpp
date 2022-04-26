#include "thread_pool.h"

// ThreadPool

ThreadPool::ThreadPool(size_t thread_count) {
    threads.emplace_back([this] () {
        WorkRoutine();
    });
}

void ThreadPool::WorkRoutine() {
    // while true : take from queue, after that runner for task processing
    throw;
}