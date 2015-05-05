#pragma once
#include "factorfactory.h"
#include "MyMatrix.h"

class LUDecomposition :
		public FactorFactory
{
public:
		LUDecomposition(MyMatrix* matrix);
		~LUDecomposition(void);
		void decomposite();
};

