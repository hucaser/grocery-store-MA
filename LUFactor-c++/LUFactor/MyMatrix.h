#pragma once
/*
* this class defines the operation in matrix
* MyMatrix is a changable matrix, its rows and columns are initialed when it's created.
* All entries are from the input of users
* It is stored in the memory
* @author: liu lihui
* @time: 2014-10-06
*/

/*	 Type: MyMatrix
*	 --------------------------------------------------------	
*    A type representing an arbitrary matrix. The elements'
*	 type in the matrix is float.
*/
class MyMatrix
{
public:
		/* Constructor: MyMatrix(int rows, int cols)
		*  Usage: MyMatrix m(3, 3);
		*  -----------------------------------------------------
		*  Constructs a new matrix of the requisite dimensions.
		*  Elements are initialied with 0.
		*/
		MyMatrix(int rows, int columns);
		/*  Destructor: ~MyMatrix(void)
		*	 ------------------------------------------------------------
		*	 free the memory used for store elements.
		*	 If you have build indexs on some elements,
		*	 these indexs will also be freed. 
		*/
		~MyMatrix(void);
		/* CopyConstructor: MyMatrix(const MyMatrix& src)
		* -------------------------------------------------------------------------------
		*  Copy both members and dynamic memory spaces of the matrix
		*/
		MyMatrix(const MyMatrix& src);
		/*  Function: void setElement(int rows, int columns, float value)
		*	------------------------------------------------------------------------------
		*	 Set the element in position m(i,j) to value,
		*	 i is row and j is col.
		*/
		void setElement(int rows, int columns, float value);
		/*  Function: float getElement(int rows, int columns)
		*	------------------------------------------------------------------------------
		*	 Return the element in position m(i,j),
		*	 i is row and j is col.
		*/
		float getElement(int rows, int columns);
		/* arithmatic operate on matrix
		*	------------------------------------------------------------------------------
		*	Example: Assume there are two matrix A, B, so the C = A + B 
		*	could be writed as MyMatrix* C = A.add(&B);
		*   If A and B are points, you can write this as MyMatrix* C = A->add(B);
		*/

		MyMatrix operator + (MyMatrix& src);
		MyMatrix operator - (MyMatrix& src);
		MyMatrix operator ^ (MyMatrix& src);
		MyMatrix& operator / (float u);
		MyMatrix& operator = (MyMatrix& src);
		MyMatrix& operator += (MyMatrix& src);
		MyMatrix& operator -= (MyMatrix& src);
		MyMatrix& operator ^= (MyMatrix& src);
		// get the norm of one column
		float getNorm(int column);

		friend int _tmain(int argc, _TCHAR* argv[]);

private:
		//when change rows, you just need to change the rowpoint in rowArray
		float** rowArray;
		int* p;
		int rows;
		int columns;

		friend class FactorFactory;
		friend class QRDecomposition;
		friend class LUDecomposition;
		friend class HouseholderReduction;
		friend class GivensReduction;
		friend class MyMatrix;
};

