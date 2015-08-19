#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int outputfile(int*array,int n)
{
	ofstream Uneaven("Uneaven.dat", ios::app);
	ofstream Eaven("Eaven.dat", ios::app);

	for (int i = 0; i <n; i++)
	{
		if (array[i] & 1)
			Uneaven << array[i];
		else
			Eaven << array[i];
	}
	Eaven.close();
	Uneaven.close();
	return 0;
}


int readfile(int *array, int n)
{
	int i = 0;
	ifstream file("Data.dat", ios::binary);
	while (!file.eof())
	{
		file >> array[i];
		i++;
	}
	file.close();
	for (i = 0; i < n; i++)
	{
		cout << " [" << array[i] << "]";
	}
	cout << endl;
	return 0;
}

int main()
{
	int size;
	cout << "Enter number of elements: ";
	cin >> size;
	int* filearray = new int[size];
	readfile(filearray, size);
	outputfile(filearray,size);
	delete[] filearray;
	_getch();
}