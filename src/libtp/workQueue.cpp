//
// Created by chris on 5/25/20.
//

#include "workQueue.h"


namespace tp {

    std::mutex lock;

    template<class T>
    workQueue<T>::workQueue(void) {
        size = 0;
        toDo = std::queue<task_s<T>>();
    }

    template<class T>
    workQueue<T>::~workQueue() = default;


    template<class T>
    task_s<T> workQueue<T>::dequeueWork() {
        lock.lock();
        task_s<T> someWork = toDo.front();
        lock.unlock();
        return someWork;
    }

    template<class T>
    template<class... Args>
    void workQueue<T>::addWork(T (*function)(Args...), Args... args) {
        std::function<T> f{std::bind(function, args...)};
        task_s<T> task = {f};
        lock.lock();
        toDo.push(task);
        lock.unlock();
    }

    template<class T>
    int workQueue<T>::workLeftToDo() {
        return size;
    }

    template<class T>
    bool workQueue<T>::isWorkDone() {
        return size == 0;
    }


}



