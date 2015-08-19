#pragma once
#include "Step.h"

class Dy
{
public:
	Dy();
	void set_array_1(Step*, int);
	void set_array_2(Dy*);
	~Dy();
	int dy_num=0;
	float *array_dy;
};

