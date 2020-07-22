#include <iostream>
#include <fstream>
#include "matrix.h"

#define MAX_BUFFER_LENGTH 1024

using namespace std;


matrix *unpackMatrix(ifstream& file) {
    char readBuffer[MAX_BUFFER_LENGTH];
    return nullptr;
}

void singleThreaded(char **files) {
    ifstream firstMatrix (files[0], ios::in);
    ifstream secondMatrix (files[1], ios::in);
    while (!firstMatrix.eof()) {
    }

}

int main(int argc, char **argv) {

    return 0;
}
