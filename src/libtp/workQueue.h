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
        std::function<T(Args...)> function;
        T *returnValue;
    };

    template<class T, class... Args>
    class workQueue {

        std::queue<task_s<T,Args...>*> toDo;
        int size;

    public:


        workQueue(T (*function)(Args...)) {
            size = 0;
            toDo = std::queue<task_s<T, Args...>*>();
        }

        void addWork(T (*function)(Args...), Args... args) {
            task_s<T, Args...> *task = new task_s<T, Args...>;
            task->function = std::bind(function, args...);
            lock.lock();
            toDo.push(task);
            lock.unlock();
            size++;
        }

        task_s<T, Args...> *dequeueWork() {
            lock.lock();
            task_s<T, Args...> *someWork = toDo.front();
            lock.unlock();
            size--;
            return someWork;
        }

        int workLeftToDo() {
            return size;
        }

        bool isWorkDone() {
            return size == 0;
        }

    };

}

#endif //MATRIXOPERATIONS_WORKQUEUE_H
