//
// Created by chris on 5/28/20.
//

#include <memory>
#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../src/libtp/threadPool.h"




using namespace tp;

#define MAXTHREADS 4

int foo(int i, int j) {
    std::cout << i + j;
    return i + j;
}

TEST(ThreadPoolTest, addWork) {

    threadPool<int> test(MAXTHREADS);
    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            int g = 0;
            int *returnVal = &g;
            test.addWork([i, j] () { return foo(i, j); }, returnVal);
        }
    }
    test.waitUntilDone();
}

