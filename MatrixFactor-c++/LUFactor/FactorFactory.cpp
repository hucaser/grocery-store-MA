#include "StdAfx.h"
#include "FactorFactory.h"


FactorFactory::FactorFactory(MyMatrix* matrix)
{
		int row = matrix->rows;
		int column = matrix->columns;
		this->matrix = new MyMatrix(row, column);
		for(int i = 0; i < row; i++){
				for(int j=0; j < column; j++){
						this->matrix->setElement(i, j, matrix->getElement(i, j));
				}
		}
}


FactorFactory::~FactorFactory(void)
{
}
