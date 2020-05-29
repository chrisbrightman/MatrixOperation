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

        virtual void addWork(std::function<T()> function, T* result) {
            task_s<T> *task = new task_s<T>;
            task->function = function;
            task->returnValue = result;
            lock.lock();
            toDo.push(task);
            size++;
            lock.unlock();
        }

        virtual task_s<T> *dequeueWork() {
            lock.lock();
            if (isWorkDone()) {
                return nullptr;
            }
            task_s<T> *someWork = toDo.front();
            toDo.pop();
            size--;
            lock.unlock();
            return someWork;
        }

        virtual int workLeftToDo() {
            return size;
        }

        virtual bool isWorkDone() {
            return size == 0;
        }

    };

}

#endif //MATRIXOPERATIONS_WORKQUEUE_H
