
project(matrixops LANGUAGES CXX C)

add_executable(MatrixOperations "main.cpp")

add_library(libmx "matrix.h" "matrix.cpp")

list(APPEND MATRIX_LIBS libmx)

option(BUILD_WITH_CUDA "use the cuda impelmentation" NO)

target_include_directories(MatrixOperations PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_WITH_CUDA)
	include(checkLanguage)
	check_language(CUDA)
	enable_language(CUDA)	
	if(NOT DEFINED CMAKE_CUDA_STANDARD)
		set(CMAKE_CUDA_STANDARD 11)
		set(CMAKE_CUDA_STANDARD_REQUIRED ON)
	endif()
	add_subdirectory(cuda)
	target_include_directories(MatrixOperations PRIVATE cuda)
	list(APPEND MATRIX_LIBS libcuda)
endif()

add_subdirectory(cpu)

list(APPEND MATRIX_LIBS libcpu)

target_include_directories(MatrixOperations PRIVATE cpu)

target_link_libraries(MatrixOperations ${MATRIX_LIBS})
