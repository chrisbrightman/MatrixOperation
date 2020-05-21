//
// Created by chris on 5/12/2020.
//

#ifndef MATRIXOPERATIONS_MATRIX_H
#define MATRIXOPERATIONS_MATRIX_H

class matrix {
    int **content;
    int rowSize;
    int colSize;
public:
    matrix(int rowSize, int colSize);
    matrix(const matrix& toCopy);
    ~matrix();
    matrix *operator + (const matrix&);
    matrix * operator - (const matrix&);
    matrix * operator * (const matrix&);
    matrix invert(const matrix&);
    void setCell(int rowIndex, int cellIndex, int value);
    int getItem(int rowIndex, int cellIndex) const;
private:
    void scaleVector(int* buffer, int scaler, const int *vector, int norm);
    int **makeDoubleVector(int normOne, int normTwo) const;

    void linearCombination(int *buffer, const int *vectorOne, const int *vectorTwo, int normOne, int normTwo);
};



#endif //MATRIXOPERATIONS_MATRIX_H
