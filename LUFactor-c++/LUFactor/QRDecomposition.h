#pragma once
#include "factorfactory.h"
#include "MyMatrix.h"

class QRDecomposition :
		public FactorFactory
{
public:
		QRDecomposition(MyMatrix* matrix);
		~QRDecomposition(void);
		void decomposite();
private:
		float getNorm(float* vector, int length);
		MyMatrix* RMatrix;
		float getInnerProduct(int column1, int column2);
		float getColNorm(int column);
};

