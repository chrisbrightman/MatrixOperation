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
        workQueue<T> workQ;
        bool isDone;

    public:


        threadPool(unsigned int maxThreads) {
            workQ = workQueue<T>();
            isDone = false;
            threads = std::stack<std::thread>();
            for (int i = 0; i < maxThreads; i++) {
                threads.push(std::thread(&threadPool::operate, this));
            }
        }

        template<class... Args>
        void addWork(std::function<T(Args...)> work, Args... args) {
            workQ.addWork( [work, args...] (Args...) { work(args...); });
        }

    private:

        template<class... Args>
        void operate() {
            while (!isDone) {
                std::function<T(Args...)> toDo = workQ.dequeueWork();
                toDo();
            }
        }

    };


}


#endif //MATRIXOPERATIONS_THREADPOOL_H
