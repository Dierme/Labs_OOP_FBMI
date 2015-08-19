#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>
#include "Step.h"
#include "Dy.h"
#include <vld.h>

using namespace std;

long double fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

void main()
{
	int i = -1;
	float x_0, y;
	int n = 10;

	Step *array_of_steps = new Step[n];

	bool ch_table;
	cout << "Calculate default table(1) / Enter new table(0)";
	cin >> ch_table;

	if (ch_table == 1)
	{
		x_0 = 0.101; y = 1.26183;
		array_of_steps[0].setter(x_0, y, &i);

		x_0 = 0.106; y = 1.27644;
		array_of_steps[1].setter(x_0, y, &i);

		x_0 = 0.111; y = 1.29122;
		array_of_steps[2].setter(x_0, y, &i);

		x_0 = 0.116; y = 1.30617;
		array_of_steps[3].setter(x_0, y, &i);

		x_0 = 0.121; y = 1.32130;
		array_of_steps[4].setter(x_0, y, &i);

		x_0 = 0.126; y = 1.33660;
		array_of_steps[5].setter(x_0, y, &i);

		x_0 = 0.131; y = 1.35207;
		array_of_steps[6].setter(x_0, y, &i);

		x_0 = 0.136; y = 1.36773;
		array_of_steps[7].setter(x_0, y, &i);

		x_0 = 0.141; y = 1.38357;
		array_of_steps[8].setter(x_0, y, &i);

		x_0 = 0.146; y = 1.39959;
		array_of_steps[9].setter(x_0, y, &i);

		x_0 = 0.151; y = 1.41579;
		array_of_steps[10].setter(x_0, y, &i);
	}

	else
	{
		cout << "Enter x_0: "; cin >> x_0;
		cout << "Enter y_0: "; cin >> y; cout << endl;
		array_of_steps[0].setter(x_0, y, &i);

		cout << "Enter x_1: "; cin >> x_0;
		cout << "Enter y_1: "; cin >> y; cout << endl;
		array_of_steps[1].setter(x_0, y, &i);

		cout << "Enter x_2: "; cin >> x_0;
		cout << "Enter y_2: "; cin >> y; cout << endl;
		array_of_steps[2].setter(x_0, y, &i);

		cout << "Enter x_3: "; cin >> x_0;
		cout << "Enter y_3: "; cin >> y; cout << endl;
		array_of_steps[3].setter(x_0, y, &i);

		cout << "Enter x_4: "; cin >> x_0;
		cout << "Enter y_4: "; cin >> y; cout << endl;
		array_of_steps[4].setter(x_0, y, &i);

		cout << "Enter x_5: "; cin >> x_0;
		cout << "Enter y_5: "; cin >> y; cout << endl;
		array_of_steps[5].setter(x_0, y, &i);

		cout << "Enter x_6: "; cin >> x_0;
		cout << "Enter y_6: "; cin >> y; cout << endl;
		array_of_steps[6].setter(x_0, y, &i);

		cout << "Enter x_7: "; cin >> x_0;
		cout << "Enter y_7: "; cin >> y; cout << endl;
		array_of_steps[7].setter(x_0, y, &i);

		cout << "Enter x_8: "; cin >> x_0;
		cout << "Enter y_8: "; cin >> y; cout << endl;
		array_of_steps[8].setter(x_0, y, &i);

		cout << "Enter x_9: "; cin >> x_0;
		cout << "Enter y_9: "; cin >> y; cout << endl;
		array_of_steps[9].setter(x_0, y, &i);

		cout << "Enter x_10: "; cin >> x_0;
		cout << "Enter y_10: "; cin >> y; cout << endl;
		array_of_steps[10].setter(x_0, y, &i);
	}

	array_of_steps[0].show_element();
	array_of_steps[1].show_element();
	array_of_steps[2].show_element();
	array_of_steps[3].show_element();
	array_of_steps[4].show_element();
	array_of_steps[5].show_element();
	array_of_steps[6].show_element();
	array_of_steps[7].show_element();
	array_of_steps[8].show_element();
	array_of_steps[9].show_element();
	array_of_steps[10].show_element();
	_getch();

	Dy *array_dy_1 = new Dy;
	array_dy_1->set_array_1(array_of_steps, n);
	Dy *array_dy_2 = new Dy;
	array_dy_2->set_array_2(array_dy_1);
	Dy *array_dy_3 = new Dy;
	array_dy_3->set_array_2(array_dy_2);
	Dy *array_dy_4 = new Dy;
	array_dy_4->set_array_2(array_dy_3);
	Dy *array_dy_5= new Dy;
	array_dy_5->set_array_2(array_dy_4);

	cout << setprecision(5) << array_dy_1->array_dy[0] << setw(15) << setprecision(4) << array_dy_2->array_dy[0] << setw(15) << setprecision(3) << array_dy_3->array_dy[0] << setw(15) << setprecision(2) << array_dy_4->array_dy[0] << setw(15) << setprecision(1) << array_dy_5->array_dy[0] << endl;
	cout << setprecision(5) << array_dy_1->array_dy[1] << setw(15) << setprecision(4) << array_dy_2->array_dy[1] << setw(15) << setprecision(3) << array_dy_3->array_dy[1] << setw(15) << setprecision(1) << array_dy_4->array_dy[1] << endl;
	cout << setprecision(5) << array_dy_1->array_dy[2] << setw(15) << setprecision(4) << array_dy_2->array_dy[2] << setw(15) << setprecision(3) << array_dy_3->array_dy[2] << endl;
	cout << setprecision(5) << array_dy_1->array_dy[3] << setw(15) << setprecision(4) << array_dy_2->array_dy[3] << endl;
	cout << setprecision(5) << array_dy_1->array_dy[4] << endl;

	_getch();

	int mid_elem = n / 2;
	float x;
	float q = 0;
	float N = 0;
	bool choose;

	do
	{

		cout << "Enter X: ";
		cin >> x;
	
	float h = array_of_steps[1].x - array_of_steps[0].x;
	if (x < array_of_steps[mid_elem].x)
	{
		if (x < (array_of_steps[mid_elem - 4].x))
			{
				q = (x - array_of_steps[mid_elem - 5].x) / h;
				N = array_of_steps[mid_elem - 5].y + q*array_dy_1->array_dy[mid_elem - 5]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem - 5] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem - 5] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem - 5] / fact(4);
			}
			if (x < (array_of_steps[mid_elem - 3].x))
			{
				q = (x - array_of_steps[mid_elem - 4].x) / h;
				N = array_of_steps[mid_elem - 4].y
					+ q*array_dy_1->array_dy[mid_elem - 4]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem - 4] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem - 4] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem - 4] / fact(4);
			}

			if (x < (array_of_steps[mid_elem - 2].x))
			{
				q = (x - array_of_steps[mid_elem - 3].x) / h;
				N = array_of_steps[mid_elem - 3].y
					+ q*array_dy_1->array_dy[mid_elem - 3]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem - 3] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem - 3] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem - 3] / fact(4);
			}
			if (x < (array_of_steps[mid_elem - 1].x))
			{
				q = (x - array_of_steps[mid_elem - 2].x) / h;
				N = array_of_steps[mid_elem - 2].y
					+ q*array_dy_1->array_dy[mid_elem - 2]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem - 2] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem - 2] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem - 2] / fact(4);
			}
			else
			{
				q = (x - array_of_steps[mid_elem - 1].x) / h;
				N = array_of_steps[mid_elem - 1].y
					+ q*array_dy_1->array_dy[mid_elem - 1]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem - 1] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem - 1] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem - 1] / fact(4);
			}
	}
	else
		{
		if (x < (array_of_steps[mid_elem + 1].x))
			{
				q = (x - array_of_steps[mid_elem + 1].x) / h;
				N = array_of_steps[mid_elem +1].y
					+ q*array_dy_1->array_dy[mid_elem]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem - 1] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem - 2] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem - 3] / fact(4);
			}
		if (x < (array_of_steps[mid_elem + 2].x))
			{
				q = (x - array_of_steps[mid_elem + 2].x) / h;
				N = array_of_steps[mid_elem + 2].y
					+ q*array_dy_1->array_dy[mid_elem+1]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem - 1] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem - 2] / fact(4);
			}
		if (x < (array_of_steps[mid_elem + 3].x))
			{
				q = (x - array_of_steps[mid_elem + 3].x) / h;
				N = array_of_steps[mid_elem + 3].y
					+ q*array_dy_1->array_dy[mid_elem + 2]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem+1] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem - 1] / fact(4);
			}
		if (x < (array_of_steps[mid_elem + 4].x))
			{
				q = (x - array_of_steps[mid_elem + 4].x) / h;
				N = array_of_steps[mid_elem + 4].y
					+ q*array_dy_1->array_dy[mid_elem + 3]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem + 2] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem+1] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem] / fact(4);
			}
			else
			{
				q = (x - array_of_steps[mid_elem + 5].x) / h;
				N = array_of_steps[mid_elem + 5].y
					+ q*array_dy_1->array_dy[mid_elem + 4]
					+ q*(q - 1)*array_dy_2->array_dy[mid_elem + 3] / fact(2)
					+ q*(q - 1)*(q - 2)*array_dy_3->array_dy[mid_elem + 2] / fact(3)
					+ q*(q - 1)*(q - 2)*(q - 3)*array_dy_4->array_dy[mid_elem+1] / fact(4);
			}
		}
		cout << "approximate: " << N << endl;
		cout << "Would you like to calculate another point? Yes(1)/No(0) ";
		cin >> choose; cout << endl;
		_getch();

	} while (choose == 1);

	delete  array_dy_2;
	delete  array_dy_3;
	delete  array_dy_4;
	//delete  array_dy_1;
	//delete [] array_of_steps;
}