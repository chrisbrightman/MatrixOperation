//
// Created by chris on 5/12/2020.
// this is a matrix that only uses single threaded operations for its 
// opertaions 
//

#ifndef MATRIXOPERATIONS_MATRIX_H
#define MATRIXOPERATIONS_MATRIX_H

class matrix {
    /// <summary>
    /// content: content of matrix; orientation [row][col]
    /// rowsize: the size of the row
    /// colSize: the size of the columns
    /// </summary>
    int **content;
    int rowSize;
    int colSize;
public:
    /// <summary>
    /// main constructor creates a blank matrix
    /// </summary>
    /// <param name="rowSize"> the row dimension</param>
    /// <param name="colSize"> the column dimension</param>
    matrix(int rowSize, int colSize);

    /// <sumery>
    /// the deconrtuctor
    /// </summary>
    ~matrix();

    /// <summary>
    /// impelmentation of a matrix add
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to sum matrix</returns>
    matrix *operator + (const matrix&);

    /// <summary>
    /// the subtraction opertor 
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to resultant matrix</returns>
    matrix * operator - (const matrix&);

    /// <summary>
    /// multiplying two matriceis
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to result</returns>
    matrix * operator * (const matrix&);

    /// <summary>
    /// creates the transpose of the matrix this
    /// </summary>
    /// <returns> the transposed matrix </returns>
    matrix *invert();

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
    void scaleVector(int* buffer, int scaler, const int *vector, int norm);
    int **makeDoubleVector(int normOne, int normTwo) const;

    void linearCombination(int *buffer, const int *vectorOne, const int *vectorTwo, int normOne, int normTwo);
};



#endif //MATRIXOPERATIONS_MATRIX_H
