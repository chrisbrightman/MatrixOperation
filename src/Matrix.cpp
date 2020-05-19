//
// Created by chris on 5/12/2020.
//

#include <cstdlib>
#include "Matrix.h"


Matrix::Matrix(int rowSize, int colSize) {
    this->rowSize = rowSize;
    this->colSize = colSize;
    matrix = makeDoubleVector(rowSize, colSize);
}

Matrix *Matrix::operator+(const Matrix& other) {
    Matrix *newMatrix = new Matrix(rowSize, colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            newMatrix->setCell(i, j, matrix[i][j] + other.getItem(i, j));
        }
    }
    return newMatrix;
}

Matrix *Matrix::operator-(const Matrix & other ) {
    Matrix *newMatrix = new Matrix(rowSize, colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            newMatrix->setCell(i, j, matrix[i][j] - other.getItem(i, j));
        }
    }
    return newMatrix;
}

Matrix *Matrix::operator*(const Matrix & other) {
    if (colSize != other.rowSize) {
        exit(1);
    }

    auto *newMatrix = new Matrix(this->rowSize, this->colSize);
    for (int i = 0; i < rowSize; i++) {
        newMatrix->matrix[i] = linearCombination(this->matrix[i], matrix[i], colSize, colSize);
    }
    return newMatrix;
}

Matrix Matrix::invert(const Matrix &) {
    return Matrix(0, 0);
}

int Matrix::getItem(int rowIndex, int cellIndex) const {
    return matrix[rowIndex][cellIndex];
}

void Matrix::setCell(int rowIndex, int cellIndex, int value) {
    matrix[rowIndex][cellIndex] = value;
}

int *Matrix::scaleVector(int scaler, const int *vector, int norm) {
    int *newVector = new int [norm];
    for (int i = 0; i < norm; i++) {
        newVector[i] = vector[i] * scaler;
    }
    return newVector;
}

int *Matrix::linearCombination(const int *vectorOne, const int *vectorTwo, int normOne, int normTwo) {
    int **tempVector = makeDoubleVector(normOne, normTwo);
    for (int i = 0; i < normOne; i++) {
        tempVector[i] = scaleVector(vectorOne[i], vectorTwo, normTwo);
    }
    int *returnVector = new int [normOne];
    for (int i = 0; i < normOne; i++) {
        returnVector[i] = 0;
    }
    for (int i = 0; i < normOne; i++) {
        for (int j = 0; j < normTwo; j++) {
            returnVector[j] += tempVector[i][j];
        }
    }
    return returnVector;
}

int **Matrix::makeDoubleVector(int normOne, int normTwo) const {
    int **vector = new int * [rowSize];
    for (int i = 0; i < rowSize; i++) {
        vector[i] = new int [colSize];
    }
    return vector;
}

Matrix::~Matrix() {
    delete [rowSize] matrix;
    delete matrix;
}

Matrix::Matrix(const Matrix& that) {
    this->rowSize = that.rowSize;
    this->colSize = that.rowSize;
    this->matrix = makeDoubleVector(rowSize, colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            matrix[i][j] = that.matrix[i][j];
        }
    }
};
