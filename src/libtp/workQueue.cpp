//
// Created by chris on 5/25/20.
//

#include "workQueue.h"


namespace tp {

    template<class T>
    workQueue<T>::~workQueue() = default;

    template<class T>
    int workQueue<T>::workLeftToDo() {
        return size;
    }

    template<class T>
    bool workQueue<T>::isWorkDone() {
        return size == 0;
    }

}



