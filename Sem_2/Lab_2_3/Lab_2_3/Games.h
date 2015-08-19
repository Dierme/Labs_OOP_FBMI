#pragma once
#include "Software.h"

class Games:public Software
{
public:
	Games();
	Games(std::string,int);
	virtual ~Games();
	virtual void output();
private:
	int age_limit;
};

