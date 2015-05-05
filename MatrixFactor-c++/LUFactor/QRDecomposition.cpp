#include "StdAfx.h"
#include "QRDecomposition.h"
#include<stdlib.h>
#include <math.h>

QRDecomposition::QRDecomposition(MyMatrix* matrix) : FactorFactory(matrix)
{
		RMatrix = new MyMatrix(matrix->columns, matrix->columns);
}


QRDecomposition::~QRDecomposition(void)
{
}


void QRDecomposition::decomposite()
{
		int columns = matrix->columns;
		int rows = matrix->rows;
		float* vector = (float*)malloc(sizeof(float)*rows);

		// operation on column 0
		for(int j = 0; j < rows; j++){
				vector[j] = matrix->getElement(j, 0);
		}
		float norm = getNorm(vector, rows);
		RMatrix->setElement(0, 0, norm);
		for(int j = 0; j < rows; j++){
				matrix->setElement(j, 0, vector[j] / norm);
		}

		//operation on other columns
		for(int i=1; i < columns; i++){
				//deduct
				for(int j=0; j < i; j++){
						float innerProduct = getInnerProduct(j, i);
						RMatrix->setElement(j,i,innerProduct);
						for(int k = 0; k < rows; k++){
								float element = matrix->getElement(k, j);
								float value = matrix->getElement(k, i);
								matrix->setElement(k, i, value - element * innerProduct);
						}
				}
				float norm = getColNorm(i);
				RMatrix->setElement(i, i, norm);
				for(int j = 0; j < rows; j++){
						matrix->setElement(j, i, matrix->getElement(j, i) / norm);
				}
		}

		printf("\n----------QMatrix----------\n");
		for (int i = 0; i < rows; i++){
				for (int j = 0; j < columns; j++){
						printf("%f  ", matrix->getElement(i, j));
				}
				printf("\n");
		}
		printf("\n----------RMatrix----------\n");
		for (int i = 0; i < columns; i++){
				for (int j = 0; j < columns; j++){
						printf("%f  ", RMatrix->getElement(i, j));
				}
				printf("\n");
		}
}

float QRDecomposition::getNorm(float* vector, int length){
		float sum = 0;
		for (int i = 0; i < length; i++){
				sum += vector[i]*vector[i];
		}
		return sqrt(sum);
}

float QRDecomposition::getInnerProduct(int column1, int column2)
{
		float product = 0;
		for(int i = 0; i < matrix->rows; i++){
				product += matrix->getElement(i, column1) * matrix->getElement(i, column2);
		}
		return product;
}

float QRDecomposition::getColNorm(int column)
{
		float sum = 0;
		for (int i = 0; i < matrix->rows; i++){
				float element = matrix->getElement(i, column);
				sum += element*element;
		}
		return sqrt(sum);
}