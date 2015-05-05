#include "StdAfx.h"
#include "GivensReduction.h"
#include <math.h>
#include <stdlib.h>


GivensReduction::GivensReduction(MyMatrix* matrix): FactorFactory(matrix)
{
		this->p = (MyMatrix**)malloc(sizeof(MyMatrix*)*matrix->rows*matrix->columns);
		this->pLength = 0;
}


GivensReduction::~GivensReduction(void)
{
}


void GivensReduction::decomposite()
{
		int rows = matrix->rows;
		int columns = matrix->columns;
		for(int i = 0; i < columns; i++){
				// reduce the elements below the first element iterately
				// reduce every element need a rotate matrix p
				for(int j = i+1; j < rows; j++){
						float firstElems = matrix->rowArray[i][i];
						float elem = matrix->rowArray[j][i];
						if( firstElems == 0 && elem == 0)
								continue;
						else {
								float c = firstElems / sqrt(firstElems*firstElems + elem * elem);
								float s = elem / sqrt(firstElems*firstElems + elem * elem);
								// build rotate matrix p
								MyMatrix* rotateP = new MyMatrix(rows, rows);
								for(int n = 0; n < rows; n++){
										rotateP->rowArray[n][n] = 1;
								}
								rotateP->rowArray[i][i] = c;
								rotateP->rowArray[i][j] = s;
								rotateP->rowArray[j][i] = -s;
								rotateP->rowArray[j][j] = c;
								(*matrix)=(*rotateP)^(*matrix);
								//printf p printf matrix
								/*printf("\n----------Matrix----------\n");
								for (int i = 0; i < rows; i++){
										for (int j = 0; j < columns; j++){
												printf("%f  ", matrix->getElement(i, j));
										}
										printf("\n");
								}*/
								printf("\n----------PMatrix----------\n");
								for (int i = 0; i < rows; i++){
										for (int j = 0; j < rows; j++){
												printf("%f  ", rotateP->getElement(i, j));
										}
										printf("\n");
								}
								this->p[pLength] = rotateP;
								this->pLength++;
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
}