//
// Created by chris on 5/26/20.
//

#include "gtest/gtest.h"
#include "../../src/libtp/workQueue.h"

using namespace tp;

void foo(int i, char j) {

}

TEST(ThreadPoolWorkQueue, addWork) {
    workQueue<void> test = workQueue<void>();
    test.addWork(foo,1,'f');
    EXPECT_EQ(test.workLeftToDo(), 1);
    EXPECT_EQ(test.isWorkDone(), false);
}

