#include <iostream>
#include "Matrix.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Matrix matrix(1, 2);
    matrix + matrix;
    return 0;
}
