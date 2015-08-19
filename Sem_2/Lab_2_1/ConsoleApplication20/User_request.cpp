#include "User_request.h"

User_request::User_request()
{
}

User_request::~User_request()
{
}


void User_request::Sort_by_age(Student* citizen,int min_age)
{
	
	for (int i = 0; i < 10; i++)
	{
		int a = citizen[i].get_age();
		if (a > min_age)
			citizen[i].show_citizen();
	}
}

void User_request::High_edu_citz(Student* citizen)
{
	for (int i = 0; i < 10; i++)
	{
		if (citizen[i].get_edu() == 1 )
			citizen[i].show_citizen();
	}
}

void User_request::Male_citz(Student* citizen)
{
	for (int i = 0; i < 10; i++)
	{
		if (citizen[i].get_gender() == 1)
			citizen[i].show_citizen();
	}
}