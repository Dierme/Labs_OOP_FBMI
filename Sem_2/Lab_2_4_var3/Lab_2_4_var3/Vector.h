#pragma once

//#include 


class Vector
{
public:
	Vector(float,float);
	~Vector();
	double calc_lenght();
	void show();
	bool operator ||(Vector);
	bool operator % (Vector);
private:
	double x;
	double y;
};



