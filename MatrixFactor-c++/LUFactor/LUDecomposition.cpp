#include "StdAfx.h"
#include "LUDecomposition.h"
#include <math.h>

LUDecomposition::LUDecomposition(MyMatrix* matrix) : FactorFactory(matrix)
{
		
		//int row = matrix->rows;
		//int column = matrix->columns;
		//this->matrix = new MyMatrix(row, column);
		//for(int i = 0; i < row; i++){
		//		for(int j=0; j < column; j++){
		//				this->matrix->setElement(i, j, matrix->getElement(i, j));
		//		}
		//}
}


LUDecomposition::~LUDecomposition(void)
{
		if(this->matrix != NULL){
				delete this->matrix;
		}
}


void LUDecomposition::decomposite()
{
		int columns = this->matrix->columns;
		int rows = this->matrix->rows;
		if(columns != rows){
				printf("The matirx is not a square matrix\n");
				printf("Cannot perform LUReduction\n");
				return;
		}
		//guassian elimilation
		for(int i = 0; i < columns; i++){
				int pivot = i;
				float max = fabs(matrix->rowArray[i][i]);
				for(int pos = i; pos<rows;pos++){
						if(fabs(matrix->rowArray[pos][i]) > max){
								max = fabs(matrix->rowArray[pos][i]);
								pivot = pos;
						}
				}
				//change rows
				if(pivot != i){
						float* tmp = matrix->rowArray[i];               
						matrix->rowArray[i] = matrix->rowArray[pivot];
						matrix->rowArray[pivot] = tmp;
						//change p
						int tp = matrix->p[i];
						matrix->p[i] = matrix->p[pivot];
						matrix->p[pivot] = tp;
				}
				/*elimilation*/
				for(int elrow = i+1; elrow < rows; elrow++){
						float factor = matrix->rowArray[elrow][i] / matrix->rowArray[i][i];
						for(int elcol = i; elcol < columns; elcol++){
								matrix->rowArray[elrow][elcol] = matrix->rowArray[elrow][elcol] - matrix->rowArray[i][elcol]*factor;
						}
						matrix->rowArray[elrow][i] = factor;
				}
		}

		if(matrix->rowArray[rows-1][columns-1] == 0) {
				printf("The matrix you input is a singular matrix, please input another matrix\n");
		}

		printf("the LU Factor of you input is :\n");
		for(int i = 0; i < rows; i++){
				printf("[  ");
				float* rowArray = matrix->rowArray[i];
				for(int j = 0; j < columns; j++){
						printf("%f  ", rowArray[j]);
				}
				printf("  ]\n");
		}
		printf("\nP is [ ");
		for (int i = 0; i < rows; i++){
				printf("%d ", matrix->p[i]);
		}
		printf("]\n\n");
		//delete matrix;
}