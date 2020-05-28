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

    template<class T>
    struct task_s {
        std::function<T()> function;
        T *returnValue;
    };

    template<class T>
    class workQueue {

        std::queue<task_s<T>*> toDo;
        int size;

    public:


        workQueue() {
            size = 0;
            toDo = std::queue<task_s<T>*>();
        }

        void addWork(std::function<T()> function) {
            task_s<T> *task = new task_s<T>;
            task->function = function;
            lock.lock();
            toDo.push(task);
            lock.unlock();
            size++;
        }

        task_s<T> *dequeueWork() {
            lock.lock();
            task_s<T> *someWork = toDo.front();
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
