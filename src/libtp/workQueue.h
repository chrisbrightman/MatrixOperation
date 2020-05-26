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

    template<class T>
    struct task_s {
        std::function<T> function;
        T returnValue;
    };

    template<class T>
    class workQueue {

        int size;
        std::queue<std::unique_ptr<task_s<T>>> toDo;

    public:


        workQueue();

        virtual ~workQueue();

        template<class... Args>
                void addWork(T (*function)(Args...), Args... args);

        int workLeftToDo();

        bool isWorkDone();

        task_s<T> dequeueWork();


    };

}

#endif //MATRIXOPERATIONS_WORKQUEUE_H
