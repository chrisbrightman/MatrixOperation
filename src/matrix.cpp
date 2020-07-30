
#include "matrix.h"

matrix::matrix(int rowSize, int colSize) {
    this->rowSize = rowSize;
    this->colSize = colSize;
    raw = makeDoubleVector(rowSize, colSize);
}

matrix::~matrix() {
    for (int i = 0; i < rowSize; i++) {
        delete [] raw[i];
    }
    delete [] raw;
}

double** matrix::makeDoubleVector(int normOne, int normTwo)
{
	double **vector = new double * [normOne];
	for (int i = 0; i < normOne; i++) {
		vector[i] = new double [normTwo];
	}
	return vector;
}
