
#include "cpuMatrix.h"
#include <thread>
#include "tpmain.h"

//////////////////
// constructors //
//////////////////

/// <summary>
/// </summary>
/// <param name="rowSize"></param>
/// <param name="colSize"></param>
/// <returns></returns>
cpuMatrix::cpuMatrix(int rowSize, int colSize) {
    this->rowSize = rowSize;
    this->colSize = colSize;
    content = makeDoubleVector(rowSize, colSize);
    maxThreads = std::thread::hardware_concurrency();
}

cpuMatrix::~cpuMatrix() {
    for (int i = 0; i < rowSize; i++) {
        delete [] content[i];
    }
    delete [] content;
}

///////////////////
// public methods//
///////////////////


std::shared_ptr<cpuMatrix> cpuMatrix::operator+(const cpuMatrix& other) {
    return runThreads(add, other);
}

std::shared_ptr<cpuMatrix> cpuMatrix::operator-(const cpuMatrix& other) {
    return runThreads(subtract, other);
}

std::shared_ptr<cpuMatrix> cpuMatrix::operator*(const cpuMatrix& other) {
	return nullptr;
}

std::shared_ptr<cpuMatrix> cpuMatrix::invert() {
    std::unique_ptr<std::thread[]> threads (new std::thread [rowSize * colSize]);
    std::shared_ptr<cpuMatrix> result(new cpuMatrix(rowSize, colSize));
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            threads[i * rowSize + j] = std::thread(toInvert, i, j, content, result->content);
        }
    }
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            threads[i * rowSize + j].join();
        }
    }
    return result;
}

void cpuMatrix::setCell(int rowIndex, int cellIndex, int value) {
    content[rowIndex][cellIndex] = value;
}

int cpuMatrix::getItem(int rowIndex, int colIndex) const {
    return content[rowIndex][colIndex];
}

///////////////////////
// private methods ////
/////////////////////// 

void cpuMatrix::add(int rowIndex, int colIndex, int** one, int** two, int** result) {
    result[rowIndex][colIndex] = one[rowIndex][colIndex] + two[rowIndex][colIndex];
}

/// <summary>
/// </summary>
/// <param name="buffer"></param>
/// <param name="scaler"></param>
/// <param name="vector"></param>
/// <param name="norm"></param>
void cpuMatrix::scaleVector(int* buffer, int scaler, const int* vector, int norm) {
}

int** cpuMatrix::makeDoubleVector(int normOne, int normTwo) const {
    int **vector = new int * [normOne];
    for (int i = 0; i < normOne; i++) {
        vector[i] = new int [normTwo];
    }
    return vector;
}

void cpuMatrix::linearCombination(int* buffer, const int* vectorOne, const int* vectorTwo, int normOne, int normTwo) {
}

void cpuMatrix::subtract(int rowIndex, int cellIndex, int **one, int **two, int **result) {
    result[rowIndex][cellIndex] = one[rowIndex][cellIndex] - two[rowIndex][cellIndex];
}

std::shared_ptr<cpuMatrix> cpuMatrix::runThreads(void (*operation)(int, int, int **, int **, int **), const cpuMatrix& other) {
    std::unique_ptr<std::thread[]> threads (new std::thread [rowSize * colSize]);
    std::shared_ptr<cpuMatrix> result(new cpuMatrix(rowSize, colSize));
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            threads[i * rowSize + j] = std::thread(operation, i, j, content, other.content, result->content);
        }
    }
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            threads[i * rowSize + j].join();
        }
    }
    return result;
}

void cpuMatrix::toInvert(int rowIndex, int colIndex, int **original, int **result) {
    result[colIndex][rowIndex] = original[rowIndex][colIndex];
}
