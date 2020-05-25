//
// Created by chris on 5/22/2020.
//

#include "gtest/gtest.h"
#include "../src/cpuMatrix.h"


#define MATRIX_DIM 50
#define MATRIX_VAL 2

TEST(cpuThreaded, add) {
    cpuMatrix test1(MATRIX_DIM, MATRIX_DIM);
    cpuMatrix test2(MATRIX_DIM, MATRIX_DIM);
    for (int i = 0; i < MATRIX_DIM; i++) {
        for (int j = 0; j < MATRIX_DIM; j++) {
            test1.setCell(i,j,MATRIX_VAL);
            test2.setCell(i, j, MATRIX_VAL);
        }
    }
    cpuMatrix *output = test1 + test2;

    for (int i = 0; i < MATRIX_DIM; i++) {
        for (int j = 0; j < MATRIX_DIM; j++) {
            EXPECT_EQ(output->getItem(i,j), MATRIX_VAL + MATRIX_VAL);
        }
    }
    delete output;
}


