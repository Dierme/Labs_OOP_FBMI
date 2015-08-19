#pragma once
#include "Student.h"

class User_request
{

public:
	void Sort_by_age(Student*,int);
	void High_edu_citz(Student*);
	void Male_citz(Student*);
	User_request();
	~User_request();
private:
	Student Citizen;
};

