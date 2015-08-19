#include "Geom_ave.h"
#include <math.h>
#include <iostream>


double Geom_ave::average_g(double a_inp, double b_inp)
{
	if (a_inp < 0 || b_inp < 0)
	{
		throw 5;
		return 0;
	}
	else
	{
		std::cout << "Average geometry = ";
		return sqrt(a_inp*b_inp);
	}
}
	