#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

int Backup(int *array1, int n1, int* array2, int n2, int*array3)
{
	int i = 0;
	for (array2[i]; i < n2; i++)
	{
		array1[array2[i]] = array3[i];
	}
	return 0;
}

int SearchUneven(int *array1, int n1, int *array2,int *array3)
{
	int usize = 0;
	for (int i = 0; i < n1; i++)
	{
		if (array1[i] & 1)
		{
			array2[usize] = i;
			array3[usize] = array1[i];
			++usize;
		}
	}
	return usize;
}

int random(int *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = 1 + rand() % 49;
	}
	return 0;
}

int OutputArray(int *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl << endl;
	return 0;
}

int InsertSort(int *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] < temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}

	return 0;
}

int main()
{
	srand(time(NULL));
	int size, usize;

	cout << "Enter size: ";
	cin >> size; cout << endl;

	int *a = new int[size];
	int *UevNum = new int[size];
	int *UevVal = new int[size];
	cout << "Current array" << endl;

	random(a, size);
	OutputArray(a, size);

	usize = SearchUneven(a, size, UevNum, UevVal);
	cout << "Uneavem Number" << endl;
	OutputArray(UevNum, usize);
	cout << "Uneavem Value" << endl;
	OutputArray(UevVal, usize);

	InsertSort(UevVal, usize);
	cout << "Sorted Uneavem Value" << endl;
	OutputArray(UevVal, usize);

	Backup(a, size, UevNum, usize, UevVal);
	cout << "Backuped array" << endl;
	OutputArray(a, size);
	
	InsertSort(a, size);
	cout << "Sorted base array" << endl;
	OutputArray(a, size);

	delete [] a;
	delete[] UevNum;
	delete[] UevVal;

	_getch();
	return 0;
}