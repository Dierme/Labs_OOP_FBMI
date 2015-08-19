#include "Games.h"
#include <iostream>


Games::Games()
{
}


Games::Games(std::string name_inp, int age_limit_inp)
{
	name = name_inp;
	age_limit = age_limit_inp;
}


void Games::output()
{
	std::cout << "Name of program: " << name << std::endl;
	std::cout << "Bit of system: " << bit_of_system << std::endl;
	std::cout << "Age limit: " << age_limit <<"+" << std::endl << std::endl;
}


Games::~Games()
{
}
