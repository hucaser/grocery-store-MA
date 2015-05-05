#pragma once
#include "factorfactory.h"
#include "MyMatrix.h"

class HouseholderReduction :
		public FactorFactory
{
public:
		HouseholderReduction(MyMatrix* matrix);
		~HouseholderReduction(void);
		void decomposite();

private:
		MyMatrix** RQueue;
		int queueSize;
		MyMatrix* matrixMultiple(MyMatrix* dest, MyMatrix* src);
};

