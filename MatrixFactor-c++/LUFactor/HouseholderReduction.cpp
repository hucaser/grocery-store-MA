#include "StdAfx.h"
#include "HouseholderReduction.h"
#include <stdlib.h>


HouseholderReduction::HouseholderReduction(MyMatrix* matrix) : FactorFactory(matrix)
{
}


HouseholderReduction::~HouseholderReduction(void)
{
}

void HouseholderReduction::decomposite()
{
		int rows = matrix->rows;
		int columns = matrix->columns;
		queueSize = rows > columns ? rows : columns;
		RQueue = (MyMatrix**)malloc(sizeof(MyMatrix*)*queueSize);
		for(int i = 0; i < queueSize; i++){
				RQueue[i] = new MyMatrix(queueSize, queueSize);
		}
		if(rows == 1){
				printf("The matrix have no HouseholderReduction\n");
				return;
		}
		for(int i = 0; i < columns-1; i++){
				// u = column[i] - norm(column[i])*e[i]
				// reflector R = I - 2(u*u')/(u'*u)
				// R * A
				MyMatrix u(rows-i, 1);
				MyMatrix uT(1, rows-i);
				for(int ti = 0; ti < rows-i; ti++){
						u.setElement(ti, 0, matrix->getElement(i+ti, i));
						uT.setElement(0, ti, matrix->getElement(i+ti, i));
				}
				float uNorm = u.getNorm(0);
				u.rowArray[0][0] -= uNorm;
				uT.rowArray[0][0] -= uNorm;
				MyMatrix I(rows-i,rows-i);
				int newRow = rows-i;
				for(int ii = 0; ii < newRow; ii++) I.setElement(ii, ii, 1);

				MyMatrix tmp = u^uT;
				float norm = tmp.getNorm(0);
				tmp = tmp / (norm * norm);
				tmp += tmp;
				MyMatrix R = I - tmp;
				for(int j = 0; j < i; j++){
						RQueue[i]->setElement(j,j,1);
				}
				for(int m = i; m < rows; m++){
						for(int n = i; n < rows; n++){
								RQueue[i]->rowArray[m][n] = R.rowArray[m-i][n-i];
						}
				}
				
				MyMatrix temp = (*RQueue[i]) ^ (*matrix);
				for(int p = 0; p < rows; p++){
						for(int q = 0; q < columns; q++){
								matrix->rowArray[p][q] = temp.rowArray[p][q];
						}
				}
		}

		printf("\n----------QMatrix----------\n");
		for (int i = 0; i < rows; i++){
				for (int j = 0; j < columns; j++){
						printf("%f  ", matrix->getElement(i, j));
				}
				printf("\n");
		}
		
		for(int p = 0; p < this->queueSize-1; p++){
				printf("\n----------R%dMatrix----------\n",p);
				for (int i = 0; i < rows; i++){
						for (int j = 0; j < rows; j++){
								printf("%f  ", RQueue[p]->getElement(i, j));
						}
						printf("\n");
				}
		}
	
}

MyMatrix* HouseholderReduction::matrixMultiple(MyMatrix* dest, MyMatrix* src)
{
		int row1 = dest->rows;
		int column1 = dest->columns;
		int row2 = src->rows;
		int column2 = src->columns;

		if(column1 != row2) {
				printf("matrix cannot multiple\n");
				return NULL;
		}
		MyMatrix* result = new MyMatrix(row1, column2);
		for (int i = 0; i < row1; i++){
				for (int j = 0; j < column2; j++){
						// rowi * columnj
						for(int m = 0; m < column1; m++){
								for(int n = 0; n < row2; n++){
										float res = dest->getElement(i, m) * src->getElement(n, j);
										result->setElement(i , j, res);
								}
						}
				}
		}
		return result;
}
