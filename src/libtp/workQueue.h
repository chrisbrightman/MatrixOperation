//
// Created by chris on 5/25/20.
//

#ifndef MATRIXOPERATIONS_WORKQUEUE_H
#define MATRIXOPERATIONS_WORKQUEUE_H

#include <queue>
#include <functional>
#include <mutex>
#include <memory>

namespace tp{

    static std::mutex lock;

    template<class T, class... Args>
    struct task_s {
        std::function<T(Args...)> *function;
        T *returnValue;
    };

    template<class T>
    class workQueue {

        template<class... Args>
        std::queue<task_s<T(Args...)>> toDo;
        int size;

    public:


        workQueue() {
            size = 0;
        }

        virtual ~workQueue();

        template<class... Args>
        void addWork(T (*function)(Args...), Args... args) {
            std::function<T(Args...)> work = std::bind(function, args...);
            task_s<T,Args...> task = {new std::function<T(Args...)>(function) };
            lock.lock();
            toDo.push(task);
            lock.unlock();
        }

        task_s<T> dequeueWork() {
            lock.lock();
            task_s<T> someWork = toDo.front();
            lock.unlock();
            return someWork;
        }

        int workLeftToDo();

        bool isWorkDone();

    };

}

#endif //MATRIXOPERATIONS_WORKQUEUE_H
