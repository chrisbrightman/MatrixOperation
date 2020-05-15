//
// Created by chris on 5/12/2020.
//

#ifndef MATRIXOPERATIONS_MATRIX_H
#define MATRIXOPERATIONS_MATRIX_H

class Matrix {
    int **matrix;
    int rowSize;
    int colSize;
public:
    Matrix(int rowSize, int colSize);
    ~Matrix();
    Matrix *operator + (const Matrix&);
    Matrix * operator - (const Matrix&);
    Matrix * operator * (const Matrix&);
    Matrix invert(const Matrix&);
    void setCell(int rowIndex, int cellIndex, int value);
    int getItem(int rowIndex, int cellIndex) const;
private:
    static int *scaleVector(int scaler, const int *vector, int norm);
    int **makeDoubleVector(int normOne, int normTwo) const;

    int *linearCombination(const int *vectorOne, const int *vectorTwo, int normOne, int normTwo);
};



#endif //MATRIXOPERATIONS_MATRIX_H
