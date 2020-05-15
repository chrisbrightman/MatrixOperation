cmake_minimum_required(VERSION 3.16)
project(MatrixOperations)

set(CMAKE_CXX_STANDARD 14)

add_executable(MatrixOperations src/Matrix.h src/Matrix.cpp src/main.cpp)

add_library(MatrixStuff src/Matrix.cpp)

cmake_minimum_required(VERSION 3.0)

add_executable(unit_tests test/MatrixTest.cpp)

include(googletest/googletest/CMakeLists.txt)



