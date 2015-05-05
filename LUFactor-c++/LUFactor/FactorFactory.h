#pragma once
#include "MyMatrix.h"

class FactorFactory
{
public:
		FactorFactory(MyMatrix* matrix);
		~FactorFactory(void);
		virtual void decomposite() = 0;
protected:
		MyMatrix* matrix;
};

