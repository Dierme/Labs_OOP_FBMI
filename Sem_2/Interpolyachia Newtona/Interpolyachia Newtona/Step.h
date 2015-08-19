#pragma once
class Step
{
public:
	Step();
	Step(float,float,int*);
	void setter(float, float, int*);
	~Step();
	void show_element();
	float x, y;
	int i;
};

