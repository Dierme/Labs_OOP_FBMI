#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int InputCheck(double xbegin, double xend, double xdelta, float e)
{
	if (fabs(xend - xbegin)<(fabs(xdelta)) || (((xbegin>xend) && (xdelta > 0)) || (xbegin<xend) && (xdelta<0)) || (e>1) || (xbegin<-1) || (xend>1))
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

int outputfile(double x,double e, double* arcsin)
{
	ofstream output("output.dat", ios::app);
	output << "arcsin(" << x << ") = " << *arcsin << endl;
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

double fct(int arg)
{
	return (arg == 1) ? 1 : arg * fct(arg - 1); 
}

double arsin(double x, double eps)
{
	double v, sum = x;
	long n = 1;
	double fn = pow(x, 3) / 6.0;
	while (eps < fabs(fn))
	{
		sum += fn;
		n += 1;
		fn *= (2 * n - 1)*(2 * n - 1)*x*x;
		fn /= 2 * n*(2 * n + 1);
	}
	return sum;
}

int main()
{

	double arcsin;

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

	cout << "Teylor sum: "<<endl;
	for (; xbegin <= xend; xbegin += xdelta)
	{
		arcsin = arsin(xbegin, e);
		cout << "arcsin(" << xbegin << ") = " << arcsin << endl;
		outputfile(xbegin, e, &arcsin);
	}
	_getch();
}

