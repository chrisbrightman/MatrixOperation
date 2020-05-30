//
// Created by chris on 5/25/20.
//

#ifndef MATRIXOPERATIONS_THREADPOOL_H
#define MATRIXOPERATIONS_THREADPOOL_H


#include"../windowsMacro.h"
#include <thread>
#include <queue>
#include <stack>
#include <functional>
#include <atomic>
#include "workQueue.h"

#include <iostream>

namespace tp {

    template <class T>
    class threadPool {
        std::stack<std::thread*> threads;
        workQueue<T> *workQ;
        bool isDone;

    public:

        threadPool(unsigned int maxThreads = std::thread::hardware_concurrency()) {
            this->workQ = new workQueue<T>();
            isDone = false;
            threads = std::stack<std::thread*>();
            for (int i = 0; i < maxThreads; i++) {
                threads.push( new std::thread(&threadPool::operate, this));
            }
        }

        ~threadPool() {
            isDone = true;
            for (int i = 0; i < threads.size(); i++) {
                std::thread *thread = threads.top();
                if (thread->joinable()) {
                    thread->join();
                }
                threads.pop();
                delete thread;
            }
            delete workQ;
        }

        void addWork(std::function<T()> work, T *result) {
            workQ->addWork( work , result);
        }

        void waitUntilDone() {
            isDone = true;
            for (int i = 0; i < threads.size(); i++) {
                try {
                    std::thread *thread = threads.top();
                    if (thread->joinable()) {
                        thread->join();
                    }
                }
                catch (const std::exception& ex) {
                    std::cout << ex.what();
                }
            }
        }

    private:

        void operate() {
            try {
                /*
                if (workQ == nullptr) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));

                }
                */
                while (!isDone || !workQ->isWorkDone()) {
                    if (workQ->isWorkDone()) {
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                    }
                    lock.lock();
                    if (workQ->isWorkDone()) {
                        continue;
                    }
                    task_s<T> *toDo = workQ->dequeueWork();
                    lock.unlock();
                    if (toDo == nullptr) {
                        if (isDone) {
                            break;
                        }
                        continue;
                    }
                    T value = toDo->function();
                    toDo->returnValue = &value;
                }
            } catch (const std::exception& ex) {
                std::cout << ex.what();
                std::cout << "I'm here";

            }
        }

    };


}


#endif //MATRIXOPERATIONS_THREADPOOL_H
