#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

struct database
{
	int number, discount; char FIO[10];
};

int search(database *array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (array[i].discount == 10)
		{
			cout << "Number: " << array[i].number << endl;
			cout << "FIO: " << array[i].FIO << endl;
			cout << endl;
		}
	}
	return 0;
}

int output(database *array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Number: " << array[i].number << endl;
		cout << "Discount: " << array[i].discount << endl;
		cout <<"FIO: "<< array[i].FIO << endl;
		cout << endl;
	}
	return 0;
}

int random(database *array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		array[i].number = 1000 + rand() % 8999;
		array[i].discount = 8 + rand() % 4;
		cin >> array[i].FIO;
	}
	return 0;
}

int InsertSort(database *array, int n)
{
	for (int i = 0; i < n; i++)
	{
		database temp = array[i];
		int j = i - 1;
		while ((j >= 0) && (array[j].number > temp.number))
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}

	return 0;
}

int main ()
{
	int n;
	srand(time(NULL));
	cout << "Number of clients: "; cin >> n;

	database *array = new database[n];

	random(array, n);

	cout << endl;
	output(array, n);

	InsertSort(array, n);

	cout << "Clients with 10% discount: " << endl;
	search(array, n);

	_getch();
}  