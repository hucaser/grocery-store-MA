#include "StdAfx.h"
#include "MyMatrix.h"
#include<stdlib.h>
#include <string.h>
#include <exception>
#include <math.h>

MyMatrix::MyMatrix(int rows, int columns)
{
		this->rows = rows;
		this->columns = columns;
 		rowArray = (float**)malloc(sizeof(float*)*rows);
		this->p = (int *)malloc(sizeof(int)*rows);
		for (int i = 0; i < rows; i++){
				rowArray[i] = (float*)malloc(sizeof(float)*columns);
				memset(rowArray[i], 0, columns*sizeof(float));
				p[i] = i+1;
		}
		
}

MyMatrix::MyMatrix(const MyMatrix& src)
{
		int rows = src.rows;
		int columns = src.columns;
		this->rows = rows;
		this->columns = columns;
 		rowArray = (float**)malloc(sizeof(float*)*rows);
		this->p = (int *)malloc(sizeof(int)*rows);
		for (int i = 0; i < rows; i++){
				rowArray[i] = (float*)malloc(sizeof(float)*columns);
				memset(rowArray[i], 0, columns*sizeof(float));
				p[i] = i+1;
		}
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
						this->rowArray[i][j] = src.rowArray[i][j];
				}
		}
}

MyMatrix::~MyMatrix(void)
{
		if(rowArray != NULL){
				for(int i=0; i < rows; i++){
						free(rowArray[i]);
				}
				free(rowArray);
		}
}




void MyMatrix::setElement(int rows, int columns, float value)
{
		this->rowArray[rows][columns] = value;
}


float MyMatrix::getElement(int rows, int columns)
{
		return this->rowArray[rows][columns];
}



float MyMatrix::getNorm(int column){
		if(column >= this->columns){
				printf("matrix get norm error\n");
				return NULL;
		}
		float sum = 0;
		for (int i = 0; i < this->rows; i++){
				sum += this->rowArray[i][column] * this->rowArray[i][column];
		}
		return sqrt(sum);
}


MyMatrix MyMatrix::operator+(MyMatrix& src)
{
		int rows = src.rows;
		int columns = src.columns;
		if(rows != this->rows && columns != this->columns) {
				printf("matrix operator+ error\n");
				exit(0);
		}
		MyMatrix res(rows, columns);
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
						res.rowArray[i][j] = this->rowArray[i][j] + src.rowArray[i][j];
				}
		}
		return res;
}

MyMatrix& MyMatrix::operator=(MyMatrix& src)
{
		int rows = src.rows;
		int columns = src.columns;
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
						this->rowArray[i][j] = src.rowArray[i][j];
				}
		}
		printf("equl");
		return *this;
}

MyMatrix MyMatrix::operator^(MyMatrix& src)
{
		int row1 = this->rows;
		int column1 = this->columns;
		int row2 = src.rows;
		int column2 = src.columns;

		if(column1 != row2) {
				printf("matrix cannot multiple\n");
				exit(0);
				//return NULL;
		}
		MyMatrix result(row1, column2);
		for (int i = 0; i < row1; i++){
				for (int j = 0; j < column2; j++){
						// rowi * columnj
						float value = 0;
						for(int k = 0; k < this->columns; k ++){
								value += this->rowArray[i][k] * src.rowArray[k][j];
						}
						result.rowArray[i][j] = value;
				}
		}
		return result;
}

MyMatrix MyMatrix::operator-(MyMatrix &src)
{
		int rows = src.rows;
		int columns = src.columns;
		if(rows != this->rows || columns != this->columns){
				printf("operator - error\n");
				exit(0);
		}
		MyMatrix result(rows, columns);
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
						result.rowArray[i][j] = this->rowArray[i][j] - src.rowArray[i][j];
				}
		}
		return result;
}

MyMatrix& MyMatrix::operator+=(MyMatrix &src)
{
		int rows = src.rows;
		int columns = src.columns;
		if(rows != this->rows && columns != this->columns) {
				printf("matrix operator+ error\n");
				exit(0);
		}
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
						this->rowArray[i][j] += src.rowArray[i][j];
				}
		}
		return *this;
}

MyMatrix& MyMatrix::operator-=(MyMatrix &src)
{
		int rows = src.rows;
		int columns = src.columns;
		if(rows != this->rows || columns != this->columns){
				printf("operator - error\n");
				exit(0);
		}
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
						this->rowArray[i][j] -= src.rowArray[i][j];
				}
		}
		return *this;
}


MyMatrix& MyMatrix::operator^=(MyMatrix& src)
{
		MyMatrix result = (*this)^src;
		(*this) = result;
		return *this;
}

MyMatrix& MyMatrix::operator / (float u)
{
		if(u == 0) return *this;
		for(int i = 0; i < this->rows; i++){
				for(int j = 0; j < this->columns; j++){
						this->rowArray[i][j] /=u;
				}
		}
		return *this;
}