// LUFactor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyMatrix.h"
#include "LUDecomposition.h"
#include "QRDecomposition.h"
#include "HouseholderReduction.h"
#include "GivensReduction.h"
#include <iostream>
#include <math.h>
#include <Windows.h>
using namespace std;

void enter(){
		printf("----------------LUFator----------------\n");
				printf("please enter rows and columns\n");
				int a,b;
				//cin>>a>>b;
				int i = scanf("%d", &a);
				int j = scanf("%d", &b);
				while(getchar()!='\n'){};
				if(i == 0 || j == 0){
						printf("your input is error\n");
				} else
				printf("%d %d\n", a, b);
}


class Matrix
{
public:
		Matrix(int a, int b){
				this->a = a;
				this->b = b;
				printf("e");
		}
		~Matrix(){
				printf(" delete");
		}
		Matrix operator + (Matrix* src) {
				Matrix result(this->a + src->a, this->b + src->b);
				return result;
		}
		int a;
		int b;
};

void fun(){
	
}


int _tmain(int argc, _TCHAR* argv[])
{		
		//fun();
		while(true){
InputMatrix:
				// clean screen
				system("cls");
				printf("----------------Welcome to MatrixFator----------------\n");
				printf("% This program has 4 matrix fator method:\n");
				printf("% 1.LUFator 2.QRFactor 3.HouseholderReduction 4.GivensReduction\n");
				printf("**please enter row-numbers of matrix\n");
				int rows,columns;
				int _i = scanf("%d", &rows);
				//int _j = scanf("%d", &columns);
				while(getchar()!='\n'){};		/*用循环把缓冲区的不匹配字符读完,不然输入错误后，scanf会出错*/
				if(_i == 0){
						printf("your input is error\n");
						goto InputMatrix;
				}
				printf("**please enter columns-numbers of matrix\n");
				_i = scanf("%d", &columns);
				//int _j = scanf("%d", &columns);
				while(getchar()!='\n'){};		/*用循环把缓冲区的不匹配字符读完,不然输入错误后，scanf会出错*/
				if(_i == 0){
						printf("your input is error\n");
						goto InputMatrix;
				}else{
						printf("###the matrix has %d rows and  %d columns###\n", rows, columns);
				}
				MyMatrix* matrix = new MyMatrix(rows, columns);

				printf("**please enter matrix\n");
				for(int i = 0; i < rows; i++){
						for(int j = 0; j < columns; j++){
								float element=0;
								int _t = scanf("%f", &element);
								if(_t == 0){
										printf("the matrix you input is error\n");
										while(getchar()!='\n'){};
										delete matrix;
										goto InputMatrix;
								} else {
										matrix->rowArray[i][j] = element;
								}
						}
				}
DoFactor:
				printf("*Input factor method number. *\n");
				printf("1-LU 2-QR 3-Householder 4-Givens 5-input new matrix\n");
				int number;
				int _t = scanf("%d", &number);
				while(getchar()!='\n'){};
				switch(number){
				case 1: //1
						{
								system("cls");
								LUDecomposition* LUD = new LUDecomposition(matrix);
								LUD->decomposite();
								delete LUD;
								goto DoFactor;
						}
				case 2: //2
						{
								system("cls");
								QRDecomposition* QRD = new QRDecomposition(matrix);
								QRD->decomposite();
								delete QRD;
								goto DoFactor;
						}
				case 3: //3
						{
								system("cls");
								HouseholderReduction* hhr = new HouseholderReduction(matrix);
								hhr->decomposite();
								delete hhr;
								goto DoFactor;
						}
				case 4: //4
						{
								system("cls");
								GivensReduction* gr = new GivensReduction(matrix);
								gr->decomposite();
								delete gr;
								goto DoFactor;
						}
				case 5: //5
						{
								delete matrix;
								goto InputMatrix;
						}
				default:
						{
								printf("your input is error\n");
								goto DoFactor;
						}
				}
		}
		return 0;
}

