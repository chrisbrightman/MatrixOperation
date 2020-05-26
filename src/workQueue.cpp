//
// Created by chris on 5/25/20.
//

#include "workQueue.h"


template<class T>
workQueue<T>::workQueue() {
    toDo = std::queue<std::function<T>>();
}

template<class T>
workQueue<T>::~workQueue() = default;


template<class T>
std::function<T> workQueue<T>::dequeueWork() {
    lock.lock();
    std::function<T> someWork = toDo.front();
    lock.unlock();
    return someWork;
}

template<class T>
template<class... Args>
void workQueue<T>::addWork(T (*function)(Args...), Args... args) {
    std::function<T> f {std::bind(function, args...)};
    lock.lock();
    toDo.push(f);
    lock.unlock();
}

