#ifndef MATRIX_OPERATIONS_WINDOWS
#define MATRIX_OPERATIONS_WINDOWS


#ifdef _WIN32
#include <Windows.h>
#define WIN_EXPORT __declspec(dllexport)
#else
#define WIN_EXPORT  
#endif

#endif // MATRIX_OPERATIONS_WINDOWS