#include <iostream>
#include <conio.h>
#include  "Vector.h"
#include "vld.h"

using namespace std;



void main()
{

	
	double x=1.0;
	double y = 0.0;
	double lenght;


	Vector* vector_1 = new Vector(x, y);
	x = 0, y = 1;
	Vector* vector_2 = new Vector(x, y);
	lenght = vector_1->calc_lenght();
	vector_1->show();
	vector_2->show();

	//cout << lenght;
	_getch();
	bool t;
	t = *vector_1 % *vector_2;
	if (t)
		cout << "vectors are ortogonal" << endl;
	else
		cout << "vectors aren't ortogonal" << endl;
	_getch();

	t = *vector_1 || *vector_2;
	if (t)
		cout << "vectors are colinear" << endl;
	else
		cout << "vectors aren't colinear" << endl;
	_getch();
	delete vector_1;
	delete vector_2;
}
