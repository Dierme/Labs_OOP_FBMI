#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int InputCheck(double xbegin, double xend, double xdelta, float e)
{
	if (fabs(xend - xbegin)<(fabs(xdelta)) || (((xbegin>xend) && (xdelta > 0)) || (xbegin<xend) && (xdelta<0)) || (e>1))
	{
		cout << "Input is incorrect";
		_getch();
		exit(1);
	}

	if (xbegin > xend)
	{
		double tmp = 0;
		tmp = xend;
		xend = xbegin;
		xbegin = tmp;
		xdelta = -xdelta;
	}
	return 0;
}

int outputfile(double x, double e, double* Ex)
{
	ofstream output("output.dat", ios::app);
	output << "E^" << x << "(1+" << x << ") = " << *Ex << endl;
	output.close();
	return 0;
}


int readfile(double* xbegin, double* xend, double* xdelta, float* e)
{
	ifstream file("input.dat", ios::binary);
	if (file.fail())
	{
		cout << "INPUT.DAT doesn't exist" << endl;
		_getch();
		exit(1);
	}
	file >> *xbegin;
	file >> *xend;
	file >> *xdelta;
	file >> *e;
	file.close();
	return 0;
}

double CicleFunction(double x, double eps)
{
	double stx = x;
	double fcto = 1;
	double ex = 1;
	int i = 1;
	while (stx / fcto >= eps)
	{
		ex = ex + (i + 1)*stx / fcto;
		i++;
		stx = stx*x;
		fcto = fcto*i;
	}
	return ex;
}

int main()
{

	double Ex;

	double xbegin, xend, xdelta;
	float e;
	int input;

	do
	{
		cout << "Choose method of input: File - 1, Console - 2" << endl;
		cout << "Input: ";
		cin >> input;
		if (input == 1)
		{

			readfile(&xbegin, &xend, &xdelta, &e);
		}

		else
		{
			if (input == 2)
			{
				cout << "xbegin= ";		cin >> xbegin;
				cout << "xend= ";		cin >> xend;
				cout << "xdelta= ";		cin >> xdelta;
				cout << "e= ";			cin >> e;

			}
			else
			{
				cout << "You've chosen incorrect input method. Please, try again.";
				_getch();
				system("cls");
			}
		}
	} while ((input != 1) && (input != 2));

	InputCheck(xbegin, xend, xdelta, e);

	cout << "Teylor sum: " << endl;
	for (; xbegin <= xend; xbegin += xdelta)
	{
		Ex = CicleFunction(xbegin, e);
		cout << "E^" << xbegin << "(1+"<< xbegin <<") = "<< Ex << endl;
		outputfile(xbegin, e, &Ex);
	}
	_getch();
}

