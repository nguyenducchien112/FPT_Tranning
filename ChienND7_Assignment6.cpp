#include<iostream>
#include<string>


using namespace std;
/****************************************************** 
* Funtion name : importData
* Input	 :	pArr Pointer is allocated in function importData.
* Input  :	szRow,szCol : size of matrix.
* Output :  success : true,fail : false.
*******************************************************/
bool importData(int** pArr, int szRow, int szCol)
{
	if (pArr)
	{
		for (int iRow = 0; iRow < szRow; iRow++)
		{
			for (int iCol = 0; iCol < szCol; iCol++)
			{
				cout << "Arr[" << iRow << "][" << iCol << "] = ";
				cin >> pArr[iRow][iCol];
				cout << endl;
			}
		}
		return true;
	}
	return false;
}
/******************************************************
* Funtion name : add2Matrix
* Input	 :	pArt1, pArt2: pointer to the memory allocated in importData().
* Input  :	szRow,szCol : size of matrix.
* Output :  Returns a pointer to the memory area containing the result of matrix addition.
*******************************************************/
int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol)
{
	int** newArr = new int* [szRow];
	for (int iRow = 0; iRow < szRow; iRow++)
	{
		newArr[iRow] = new int[szCol];
	}

	if (newArr)
	{
		for (int iRow = 0; iRow < szRow; iRow++)
		{
			for (int iCol = 0; iCol < szCol; iCol++)
			{
				newArr[iRow][iCol] = pArr1[iRow][iCol] + pArr2[iRow][iCol];
			}
		}
	}
	return newArr;
}
/******************************************************
* Funtion name : printMatrix
* Input	 :	pArr pointer to the allocated memory in importData()
* Input  :	szRow,szCol : size of matrix.
*******************************************************/
void printMatrix(int** pArr, int szRow, int szCol)
{
	if (pArr)
	{
		for (int iRow = 0; iRow < szRow; iRow++)
		{
			for (int iCol = 0; iCol < szCol; iCol++)
			{
				cout << pArr[iRow][iCol] << " ";
			}
			cout << endl;
		}
	}
}
/******************************************************
* Funtion name : freeMem
* Input	 :	pArr pointer to the allocated memory in importData()
* Input  :	szRow,szCol : size of matrix.
*******************************************************/
void freeMem(int** pArr, int szRow, int szCol)
{
	for (int iRow = 0; iRow < szRow; iRow++)
	{
		delete[] pArr[iRow];
	}
	delete[] pArr;
}

int main()
{
	int** pArr1, ** pArr2;
	int szRow, szCol;
	cout << "Row : ";
	cin >> szRow;
	cout << "Colume : ";
	cin >> szCol;
	pArr1 = new int* [szRow];
	for (int iRow = 0; iRow < szRow; iRow++)
	{
		pArr1[iRow] = new int[szCol];
	}
	pArr2 = new int* [szRow];
	for (int iRow = 0; iRow < szRow; iRow++)
	{
		pArr2[iRow] = new int[szCol];
	}
	cout << "Import data matrix 1 : " << endl;
	importData(pArr1, szRow, szCol);
	cout << "Import data matrix 2 : " << endl;
	importData(pArr2, szRow, szCol);
	cout << "Matrix 1 : " << endl;
	printMatrix(pArr1,szRow,szCol);
	cout << "Matrix 2 : " << endl;
	printMatrix(pArr2,szRow,szCol);
	int** RetArr = add2Matrix(pArr1, pArr2, szRow, szCol);
	cout << "after matrix : " << endl;
	printMatrix(RetArr, szRow, szCol);

	freeMem(RetArr, szRow, szCol);
	return 0;
}