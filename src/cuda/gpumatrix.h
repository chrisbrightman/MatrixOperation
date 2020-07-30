
#include <memory>

class gpumatrix {
private:
	double** raw;
	int xaxis;
	int yaxis;
	
public:
	gpumatrix(int rowSize, int colSize);
	~gpumatrix();
	std::shared_ptr<gpumatrix> operator + (const gpumatrix& other);
	std::shared_ptr<gpumatrix> operator - (const gpumatrix& other);
	std::shared_ptr<gpumatrix> operator * (const gpumatrix& other);

	std::shared_ptr<gpumatrix> invert();

};