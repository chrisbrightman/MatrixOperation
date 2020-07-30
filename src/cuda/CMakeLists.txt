
project(cuda_matrix CUDA CXX)

add_library(libcuda STATIC "gpumatrix.cu" "gpumatrix.h")