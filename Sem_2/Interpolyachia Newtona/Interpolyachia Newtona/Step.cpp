#include "Step.h"
#include <iostream>
#include <iomanip>

Step::Step()
{
}


Step::Step(float x_inp, float y_inp, int* i_inp) : x(x_inp), y(y_inp)
{
	*i_inp = *i_inp + 1;
	i = *i_inp;
}


Step::~Step()
{
}

void Step::show_element()
{
	std::cout << "Element Numb = " << i << std::setw(20);
	std::cout <<"x = "<< x << std::setw(10);
	std::cout << "y = " << y << std::endl;
}

void Step::setter(float x_inp, float y_inp, int *i_inp)
{
	*i_inp = *i_inp + 1;
	i = *i_inp;
	x = x_inp;
	y = y_inp;
}
