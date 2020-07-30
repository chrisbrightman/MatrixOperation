//
// Created by chris on 5/12/2020.

#include "gtest/gtest.h"
#include "cpumatrix.h"

#define MATRIX_DIM 1000
#define MATRIX_VAL 2

namespace {

    /**
     * tests the add functionality
     */
    TEST(SingleThreadMatrix, add) {
        cpumatrix *test1 = new cpumatrix(MATRIX_DIM, MATRIX_DIM);
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                test1->setCell(i,j,MATRIX_VAL);
            }
        }
        cpumatrix output = *test1 + *test1;
        test1->invert();

        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                EXPECT_EQ(output.getItem(i,j), MATRIX_VAL * 2);
            }
        }
        delete test1;
    }

    TEST(SingleThreadMatrix, subtract) {
        cpumatrix *test1 = new cpumatrix(MATRIX_DIM, MATRIX_DIM);
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                test1->setCell(i,j,MATRIX_VAL);
            }
        }
        cpumatrix *output = *test1 - *test1;

        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                EXPECT_EQ(output->getItem(i,j), 0);
            }
        }
        delete output;
        delete test1;
    }

    TEST(SingleThreadMatrix, multiply) {
        cpumatrix *test1 = new cpumatrix(MATRIX_DIM, MATRIX_DIM);
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                test1->setCell(i,j,MATRIX_VAL);
            }
        }
        cpumatrix *output = *test1 * *test1;

        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                EXPECT_EQ(output->getItem(i,j), MATRIX_VAL * MATRIX_VAL * MATRIX_DIM);
            }
        }
        delete output;
        delete test1;
    }

    TEST(SingleThreadMatrix, invert) {
        cpumatrix test(MATRIX_DIM, MATRIX_DIM);
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                test.setCell(i, j, i);
            }
        }
        cpumatrix *inverted = test.invert();
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                inverted->setCell(i, j, j);
            }
        }
        delete inverted;
    }

}
