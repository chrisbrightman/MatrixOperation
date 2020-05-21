//
// Created by chris on 5/12/2020.

#include "gtest/gtest.h"
#include "../src/matrix.h"

#define MATRIX_DIM 10
#define MATRIX_VAL 2

namespace {

    /**
     * tests the add functionality
     */
    TEST(SingleThreadMatrix, add) {
        matrix *test1 = new matrix(MATRIX_DIM, MATRIX_DIM);
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                test1->setCell(i,j,MATRIX_VAL);
            }
        }
        matrix *output = *test1 + *test1;

        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                EXPECT_EQ(output->getItem(i,j), MATRIX_VAL * 2);
            }
        }
        delete output;
        delete test1;
    }

    TEST(SingleThreadMatrix, subtract) {
        matrix *test1 = new matrix(MATRIX_DIM, MATRIX_DIM);
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                test1->setCell(i,j,MATRIX_VAL);
            }
        }
        matrix *output = *test1 - *test1;

        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                EXPECT_EQ(output->getItem(i,j), 0);
            }
        }
        delete output;
        delete test1;
    }

    TEST(SingleThreadMatrix, multiply) {
        matrix *test1 = new matrix(MATRIX_DIM, MATRIX_DIM);
        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                test1->setCell(i,j,MATRIX_VAL);
            }
        }
        matrix *output = *test1 * *test1;

        for (int i = 0; i < MATRIX_DIM; i++) {
            for (int j = 0; j < MATRIX_DIM; j++) {
                EXPECT_EQ(output->getItem(i,j), MATRIX_VAL * MATRIX_VAL * MATRIX_DIM);
            }
        }
        delete output;
        delete test1;
    }

}
