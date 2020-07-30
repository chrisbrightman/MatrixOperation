
#include "gpumatrix.h"

__global__ void kernel() {

}

gpumatrix::gpumatrix(int rowSize, int colSize)
{
}

gpumatrix::~gpumatrix()
{
}

std::shared_ptr<gpumatrix> gpumatrix::operator+(const gpumatrix& other)
{
	return std::shared_ptr<gpumatrix>();
}

std::shared_ptr<gpumatrix> gpumatrix::operator-(const gpumatrix& other)
{
	return std::shared_ptr<gpumatrix>();
}

std::shared_ptr<gpumatrix> gpumatrix::operator*(const gpumatrix& other)
{
	return std::shared_ptr<gpumatrix>();
}

std::shared_ptr<gpumatrix> gpumatrix::invert()
{
	return std::shared_ptr<gpumatrix>();
}
