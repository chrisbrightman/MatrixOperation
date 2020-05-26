//
// Created by chris on 5/25/20.
//

#ifndef MATRIXOPERATIONS_WORKQUEUE_H
#define MATRIXOPERATIONS_WORKQUEUE_H

#include <queue>
#include <functional>
#include <mutex>

std::mutex lock;

template<class T>
class workQueue {

    std::queue<std::function<T>> toDo;

public:

    workQueue();

    virtual ~workQueue();

    template<class... Args>
    void addWork(T (*function)(Args...), Args... args);

    std::function<T> dequeueWork();

};

#endif //MATRIXOPERATIONS_WORKQUEUE_H
