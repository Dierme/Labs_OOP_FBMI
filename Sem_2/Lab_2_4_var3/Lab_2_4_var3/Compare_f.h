#pragma once
#include <assert.h>
#include <iostream>

double round_to(double value, double eps)
{
	assert(eps > 0);
	return floor(value / eps + 0.5) * eps;
}

int compare_1(double a, double b, double eps)
{
	double diff = floor(a / eps + 0.5) - floor(b / eps + 0.5);
	return diff < 0 ? -1 : diff > 0 ? +1 : 0;
}
