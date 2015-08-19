#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int output(int rows, int collums, int**array)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
			cout << "[" << array[i][j] << "]";
		cout << endl;
	}
	return 0;
}

int rand(int rows, int collums, int**array)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
			array[i][j] = 1 + rand() % 24;
	}
	return 0;
}

int function(int rows, int collums, int** array)
{
	int tmp = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < collums; ++j)
		{
			if (array[i][j]>tmp)
				tmp = array[i][j];
		}
		for (int j = 0; j < collums; ++j)
			array[i][j] = array[i][j] * tmp;
		tmp = 0;
	}
	cout << endl;
	return 0;
}

int main()
{
	srand(time(NULL));
	int collums, rows, tmp=0;

	cout << "rows= ";
	cin >> rows;

	cout << "collums= ";
	cin >> collums;
	cout << endl;

	int **arrayA = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		arrayA[i] = new int[collums];
	}

	rand(rows, collums, arrayA);

	cout << "Array:" << endl;
	output(rows, collums, arrayA);
	_getch();

	function(rows, collums, arrayA);

	cout << "rebuild Array:" << endl;
	output(rows, collums, arrayA);
	_getch();
	for (int i = 0; i < rows; i++)
		delete[] arrayA[i];
	delete[] arrayA;
	}
