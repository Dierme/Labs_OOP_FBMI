#include "Dy.h"

using namespace std;

Dy::Dy()
{
	array_dy = new float[10];
}

void Dy::set_array_1(Step*array_of_steps, int n)
{
	for (int a = 0; array_of_steps[a].i <= n; a++)
	{
		array_dy[a] = array_of_steps[a + 1].y - array_of_steps[a].y;
	}
	dy_num = n - 1;
}

void Dy::set_array_2(Dy* array_inp)
{
	int k = 0;
	for (int a = 0; a <= array_inp->dy_num; a++)
	{
		array_dy[a] = array_inp->array_dy[a + 1] - array_inp->array_dy[a];
		k = a;
	}
	dy_num = k-1;
}

Dy::~Dy()
{
	delete [] array_dy;
}
