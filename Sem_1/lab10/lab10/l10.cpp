
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>

using namespace std;

int function_1(int, int);
int function_2(int, int, int);


int main()
{
	int n, j, R2;
	printf("Enter size:");
	scanf_s("%i", &n);
	cout<<"Enter j:";
	cin>>j;
	printf("Enter:%i", &j);
	printf("Enter R2:");
	scanf_s("%i", &R2);
	int result_1 = function_1(j, R2);
	printf("Kolichestvo elementov:%i", &result_1);
	int result_2 = function_2(n, j, R2);
	printf("Summa elementov:%i", &result_2);
	_getch();
	return 0;
}

int function_1(int j, int R2)
{
	int k = R2 - j;
	return k;
}

int function_2(int n, int j, int R2)
{
	int * a;
	a = new int[n];
	printf("Enter elementi masssiva:");
	for (int i = 0; i < n; i++)
	{
		cout << "input a[" << i << "]=";
		cin >> a[i];
	}
	int sum = a[j];
	for (int i = j; i < R2; i++)
		sum = sum + a[i];
	return sum;
	delete[] a;
	_getch();
}
