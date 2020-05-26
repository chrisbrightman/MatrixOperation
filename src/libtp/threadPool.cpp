//
// Created by chris on 5/25/20.
//

#include "threadPool.h"

namespace tp {

    template<class T>
    threadPool<T>::threadPool(uint maxThreads) {
        work = workQueue<T>();
        isDone = false;
        threads = std::stack<std::thread>();
        for (int i = 0; i < maxThreads; i++) {
            threads.push(std::thread(&threadPool::operate, this));
        }
    }

    template<class T>
    void threadPool<T>::operate() {
        while (!isDone) {
            std::function<T> toDo = work.dequeueWork();
            toDo();
        }
    }

}



