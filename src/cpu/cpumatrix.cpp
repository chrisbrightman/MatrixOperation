//
// Created by chris on 5/12/2020.
//

#include <cstdlib>
#include <cstring>
#include "cpumatrix.h"

///////////////////
// public methods//
///////////////////

cpumatrix cpumatrix::operator+(const cpumatrix& other) {
    cpumatrix newMatrix(rowSize, colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            newMatrix.setCell(i, j, raw[i][j] + other.getItem(i, j));
        }
    }
    return newMatrix;
}

cpumatrix *cpumatrix::operator-(const cpumatrix & other ) {
    auto *newMatrix = new cpumatrix(rowSize, colSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            newMatrix->setCell(i, j, raw[i][j] - other.getItem(i, j));
        }
    }
    return newMatrix;
}

cpumatrix *cpumatrix::operator*(const cpumatrix & other) {
    if (colSize != other.rowSize) {
        exit(1);
    }

    auto *newMatrix = new cpumatrix(this->rowSize, this->colSize);
    for (int i = 0; i < rowSize; i++) {
        linearCombination(newMatrix->raw[i], this->raw[i], raw[i], colSize, colSize);
    }
    return newMatrix;
}

cpumatrix *cpumatrix::invert() {
    cpumatrix* newMatrix = new cpumatrix(this->colSize, this->rowSize);
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            newMatrix->setCell(j, i, raw[i][j]);
        }
    }
    return newMatrix;
}

int cpumatrix::getItem(int rowIndex, int cellIndex) const {
    return raw[rowIndex][cellIndex];
}

void cpumatrix::setCell(int rowIndex, int cellIndex, int value) {
    raw[rowIndex][cellIndex] = value;
}


//////////////////////////
// Private methods ///////
//////////////////////////

void cpumatrix::scaleVector(double *buffer, int scaler, const double *vector, int norm) {
    for (int i = 0; i < norm; i++) {
        buffer[i] = vector[i] * scaler;
    }
}

void cpumatrix::linearCombination(double *buffer, const double *vectorOne, const double *vectorTwo, int normOne, int normTwo) {
    double **tempVector = makeDoubleVector(normOne, normTwo);
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


