//
// Created by chris on 5/26/20.
//

#include "gtest/gtest.h"
#include "../../src/libtp/workQueue.h"
#include <functional>

using namespace tp;

void foo(int i, char j) {

}

TEST(ThreadPoolWorkQueue, addWork) {
    workQueue<void, int, char> test = workQueue<void, int, char>(foo);
    test.addWork(foo,1,'f');
    EXPECT_EQ(test.workLeftToDo(), 1);
    EXPECT_EQ(test.isWorkDone(), false);
}

int bar(int i, int j) {
    return i + j;
}

TEST(ThreadPoolWorkQueue, testWork) {
    workQueue<int, int, int> test = workQueue<int, int, int>(bar);
    test.addWork(bar, 1,1);
    task_s<int, int, int> *work = test.dequeueWork();
    //EXPECT_EQ(work->function(), 2);
}

