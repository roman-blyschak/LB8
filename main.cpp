#include <iostream>
#include <Windows.h>
#include "Matrix.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Matrix<int> matrix(5, 6);
	matrix.Random();
	matrix.Show();

	cout << "Averge = " << matrix.Averge() << endl;
	cout << "\n\n---------------------------------------------------------------------------\n\n";


	int** arr = new int* [2];
	arr[0] = new int[2];
	arr[1] = new int[2];
	arr[0][0] = 4;
	arr[0][1] = 1;
	arr[1][0] = 3;
	arr[1][1] = 4;


	matrix.SetArr( arr, 2, 2);
	matrix.Show();
	cout << endl;
	cout << "Averge = " << matrix.Averge() << endl;
	delete arr[0];
	delete arr[1];
	delete arr;

	system("pause");
	return 0;
}