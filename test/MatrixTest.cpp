//
// Created by chris on 5/12/2020.

#include "gtest/gtest.h"
#include "../src/Matrix.h"

TEST(SingleThreadMatrix, add) {
    Matrix test1(1,1);
    Matrix test2(1,1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            test1.setCell(i,j,1);
            test2.setCell(i,j,1);
        }
    }
    Matrix *output = test2 + test1;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            EXPECT_EQ(output->getItem(i,j), 2);
        }
    }
}
