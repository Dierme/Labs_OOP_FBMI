#include "Vector.h"
#include "math.h"
#include <iostream>
#include "Compare_f.h"


using namespace std;

Vector::Vector(float x_inp, float y_inp) : x(x_inp), y(y_inp) {}


Vector::~Vector(){}


double Vector::calc_lenght()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

void Vector::show()
{
	cout << "vector (" << x << "," << y << ")" << endl << endl;
}

bool Vector::operator||(Vector v_2)
{
	return compare_1(x / y, v_2.x / v_2.y, 0.001) == 0 ? true : false;
}

bool Vector::operator % (Vector v_2)
{
	return compare_1(x*v_2.x + y*v_2.y, 0, 0.001) == 0 ? true : false;
}