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

namespace tp {

    template <class T>
    class threadPool {
        std::stack<std::thread> threads;
        workQueue<T> work;
        bool isDone;

    public:


        threadPool(unsigned int maxThreads) {
            work = workQueue<T>();
            isDone = false;
            threads = std::stack<std::thread>();
            for (int i = 0; i < maxThreads; i++) {
                threads.push(std::thread(&threadPool::operate, this));
            }
        }

        void addWork(std::function<void> work);

    private:

        void operate() {
            while (!isDone) {
                std::function<T> toDo = work.dequeueWork();
                toDo();
            }
        }

    };

}


#endif //MATRIXOPERATIONS_THREADPOOL_H
