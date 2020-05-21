//
// Created by chris on 5/12/2020.
//

#include <cstdlib>
#include "matrix.h"

/////////////////////
// constructors /////
/////////////////////

matrix::matrix(int rowSize, int colSize) {
    this->rowSize = rowSize;
    this->colSize = colSize;
    content = makeDoubleVector(rowSize, colSize);
}

matrix::~matrix() {
    for (int i = 0; i < rowSize; i++) {
        delete [] content[i];
    }
    delete [] content;
}

matrix::matrix(const matrix& that) {
    this->rowSize = that.rowSize;
    this->colSize = that.rowSize;
    this->content = makeDoubleVector(rowSize, colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            content[i][j] = that.content[i][j];
        }
    }
}

///////////////////
// public methods//
///////////////////

matrix *matrix::operator+(const matrix& other) {
    matrix *newMatrix = new matrix(rowSize, colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            newMatrix->setCell(i, j, content[i][j] + other.getItem(i, j));
        }
    }
    return newMatrix;
}

matrix *matrix::operator-(const matrix & other ) {
    auto *newMatrix = new matrix(rowSize, colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            newMatrix->setCell(i, j, content[i][j] - other.getItem(i, j));
        }
    }
    return newMatrix;
}

matrix *matrix::operator*(const matrix & other) {
    if (colSize != other.rowSize) {
        exit(1);
    }

    auto *newMatrix = new matrix(this->rowSize, this->colSize);
    for (int i = 0; i < rowSize; i++) {
        linearCombination(newMatrix->content[i], this->content[i], content[i], colSize, colSize);
    }
    return newMatrix;
}

matrix matrix::invert(const matrix &) {
    return matrix(0, 0);
}

int matrix::getItem(int rowIndex, int cellIndex) const {
    return content[rowIndex][cellIndex];
}

void matrix::setCell(int rowIndex, int cellIndex, int value) {
    content[rowIndex][cellIndex] = value;
}


//////////////////////////
// Private methods ///////
//////////////////////////

void matrix::scaleVector(int *buffer, int scaler, const int *vector, int norm) {
    for (int i = 0; i < norm; i++) {
        buffer[i] = vector[i] * scaler;
    }
}

void matrix::linearCombination(int *buffer, const int *vectorOne, const int *vectorTwo, int normOne, int normTwo) {
    int **tempVector = makeDoubleVector(normOne, normTwo);
    for (int i = 0; i < normOne; i++) {
        scaleVector(tempVector[i], vectorOne[i], vectorTwo, normTwo);
    }
    for (int i = 0; i < normOne; i++) {
        buffer[i] = 0;
    }
    for (int i = 0; i < normOne; i++) {
        for (int j = 0; j < normTwo; j++) {
            buffer[j] += tempVector[i][j];
        }
    }
    for (int i = 0; i < normOne; i++) {
        delete [] tempVector[i];
    }
    delete [] tempVector;
}

int **matrix::makeDoubleVector(int normOne, int normTwo) const {
    int **vector = new int * [normOne];
    for (int i = 0; i < normOne; i++) {
        vector[i] = new int [normTwo];
    }
    return vector;
}

