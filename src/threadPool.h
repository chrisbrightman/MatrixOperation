//
// Created by chris on 5/25/20.
//

#ifndef MATRIXOPERATIONS_THREADPOOL_H
#define MATRIXOPERATIONS_THREADPOOL_H

#include <thread>
#include <queue>
#include <stack>
#include <functional>
#include "workQueue.h"

template<class T>
class threadPool {
    std::stack<std::thread> threads;
    workQueue<T> work;
    bool isDone;

public:
    threadPool(uint maxThreads);
    void addWork(std::function<void> work);

private:
    void operate();

};


#endif //MATRIXOPERATIONS_THREADPOOL_H
