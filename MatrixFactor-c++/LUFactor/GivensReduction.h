#pragma once
#include "factorfactory.h"
class GivensReduction :
		public FactorFactory
{
public:
		GivensReduction(MyMatrix* matrix);
		~GivensReduction(void);
		void decomposite();
private:
		MyMatrix** p;
		int pLength;
};

