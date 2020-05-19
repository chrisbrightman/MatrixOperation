//
// Created by chris on 5/12/2020.

#include "gtest/gtest.h"
#include "../src/Matrix.h"

namespace {
    TEST(SingleThreadMatrix, add) {
        Matrix *test1 = new Matrix(1,1);
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 1; j++) {
                test1->setCell(i,j,1);
            }
        }
        Matrix *output = *test1 + *test1;

        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 1; j++) {
                EXPECT_EQ(output->getItem(i,j), 2);
            }
        }
        delete output;
        delete test1;
    }
}
