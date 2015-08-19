#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

int function_1(int c, int* array)
{
	for (int i = 0; i < c; i++)
	{
		cout << "[ " << array[i] << "] " << endl;
	}
	return 0;
}
int function_2(int c, int* array)
{
	for (int i = 0; i < c; i++)
	{
		array[i] = rand() % 24;
	}
	return 0;
}
int main()
{
	int n, tmp=0;
	srand(time (NULL));
	cout << "n=";
	cin >> n;
	int* arrayA = new int[n];
	int* arrayB = new int[n];
	function_2(n, arrayA);
	function_2(n, arrayB);
	cout << "Array A" << endl;
	function_1(n, arrayA);
	cout << "Array B" << endl;
	function_1(n, arrayB);
	for (int i = 0; i < n; i++)
	{
		tmp = arrayA[i];
		if (arrayA[i] < arrayB[i])
		{
			arrayA[i] = tmp;
			arrayA[i] = arrayB[i];
			arrayB[i] = tmp;
		}	
	}
	cout << "rebuild A" << endl;
	function_1(n, arrayA);
	cout << "rebuild B" << endl;
	function_1(n, arrayB);
	system("pause");
	delete[] arrayA;
	delete[] arrayB;
}