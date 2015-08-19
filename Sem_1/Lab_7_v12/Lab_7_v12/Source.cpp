#include <conio.h>
#include <iostream>
#include "Geom_ave.h"
#include "vld.h"

using namespace std;

int main()
{
	double x, y, c;

flag_1: cout << "a= ";
	cin >> x;
	cout << "b= ";
	cin >> y; cout << endl;
	try
	{
		c = Geom_ave::average_g(x, y);
	}
	catch (int exeption)
	{
		if (exeption = 5)
		{
			cout << " numbers < 0 . Please, enter correct values." << endl;;
			_getch();
			goto flag_1;
			return 0;
		}
	}
	cout << c;
	_getch();
}