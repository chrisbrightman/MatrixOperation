

class matrix {
public:
	matrix(int rowSize, int colSize);
	virtual ~matrix();
protected:
	double** raw;
	int colSize;
	int rowSize;
	double** makeDoubleVector(int normOne, int normTwo);
};