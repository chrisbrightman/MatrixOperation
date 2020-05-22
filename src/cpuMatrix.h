///
/// author: chris
///


#ifndef MATRIX_CPU_MATRIX
#define MATRIX_CPU_MATRIX

class cpuMatrix {
    /// <summary>
    /// content: content of matrix; orientation [row][col]
    /// rowsize: the size of the row
    /// colSize: the size of the columns
    /// </summary>
    int **content;
    int rowSize;
    int colSize;
public:
    cpuMatrix(int rowSize, int colSize);
    ~cpuMatrix();

    /// <summary>
    /// impelmentation of a matrix add
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to sum matrix</returns>
    cpuMatrix *operator + (const cpuMatrix&);

    /// <summary>
    /// the subtraction opertor 
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to resultant matrix</returns>
    cpuMatrix * operator - (const cpuMatrix&);

    /// <summary>
    /// multiplying two matriceis
    /// </summary>
    /// <param name=""> the other matrix</param>
    /// <returns> pointer to result</returns>
    cpuMatrix * operator * (const cpuMatrix&);

    /// <summary>
    /// creates the transpose of the matrix this
    /// </summary>
    /// <returns> the transposed matrix </returns>
    cpuMatrix *invert();

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
    void add(int rowIndex, int colIndex, int **one, int **two, int  **result);

    void scaleVector(int* buffer, int scaler, const int *vector, int norm);
    int **makeDoubleVector(int normOne, int normTwo) const;

    void linearCombination(int *buffer, const int *vectorOne, const int *vectorTwo, int normOne, int normTwo);

};

#endif // MATRIX_CPU_MATRIX