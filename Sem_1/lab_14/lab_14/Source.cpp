#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int outputfile(int*array,int max,int n,int index)
{
	ofstream output("filek.dat", ios::out);
	for (int i = 0; i < n ; ++i)
	{
		if ((max%array[i]) == 0)
			output << array[i] << " ";
		
	}
	
	for (int i = 0; i < n ; ++i)
	{
			output << array[i] << " ";
	}

	output.close();
	return 0;
}

int MaxEl(int *array, int n)
{
	int MaxEl = 0;
	for (int i = 0; i < n; ++i)
	{
		if (array[i]>MaxEl)
			MaxEl = array[i];
	}
	return MaxEl;
}

int MaxElindex(int *array, int n)
{
	int MaxEl = 0,index=0;
	for (int i = 0; i < n; ++i)
	{
		if (array[i]>MaxEl)
		{
			MaxEl = array[i];
			index = i;
		}
			
	}
	return index;
}

int readfile(int *array, int n)
{
	int i = 0;
	ifstream file("filek.dat", ios::binary);
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
	int size,index;
	cout << "Enter number of elements: ";
	cin >> size;
	int* filearray = new int[size];
	readfile(filearray, size);
	MaxEl(filearray, size);
	index = MaxElindex(filearray, size);
	cout << "The Biggest element = " << MaxEl(filearray, size) << endl;
	outputfile(filearray,MaxEl(filearray, size),size,index);
	delete[] filearray;
	_getch();
}