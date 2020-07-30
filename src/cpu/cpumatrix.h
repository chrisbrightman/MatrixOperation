//
// Created by chris on 5/12/2020.
// this is a matrix that only uses single threaded operations for its 
// opertaions 
//

#ifndef MATRIXOPERATIONS_MATRIX_H
#define MATRIXOPERATIONS_MATRIX_H

#include "matrix.h"

class cpumatrix : matrix {
    /// <summary>
    /// content: content of matrix; orientation [row][col]
    /// rowsize: the size of the row
    /// colSize: the size of the columns
    /// </summary>
public:
    /// <summary>
    /// main constructor creates a blank matrix
    /// </summary>
    /// <param name="rowSize"> the row dimension</param>
    /// <param name="colSize"> the column dimension</param>
    cpumatrix(int rowSize, int colSize) : matrix(rowSize, colSize) {};

    /// <summary>
    /// impelmentation of a matrix add
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to sum matrix</returns>
    cpumatrix operator + (const cpumatrix&);

    /// <summary>
    /// the subtraction opertor 
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to resultant matrix</returns>
    cpumatrix * operator - (const cpumatrix&);

    /// <summary>
    /// multiplying two matriceis
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to result</returns>
    cpumatrix * operator * (const cpumatrix&);

    /// <summary>
    /// creates the transpose of the matrix this
    /// </summary>
    /// <returns> the transposed matrix </returns>
    cpumatrix *invert();

    /// <summary>
    /// this will set a single cell's value
    /// </summary>
    /// <param name="rowIndex"> the rows index</param>
    /// <param name="cellIndex"> the columns index</param>
    /// <param name="value">the value of the </param>
    void setCell(int rowIndex, int cellIndex, int value);

    /// <summary>
    /// this gets a value from the matrix
    /// </summary>
    /// <param name="rowIndex"> the row index to get</param>
    /// <param name="cellIndex"> the column index</param>
    /// <returns> the value in that row index</returns>
    int getItem(int rowIndex, int cellIndex) const;
private:
    void scaleVector(double* buffer, int scaler, const double *vector, int norm);
    void linearCombination(double *buffer, const double *vectorOne, const double *vectorTwo, int normOne, int normTwo);
};



#endif //MATRIXOPERATIONS_MATRIX_H
