#include "Software.h"
#include <iostream>


Software::Software(std::string name_inp) :bit_of_system ("x64_and_x32" )
{
	name = name_inp;
}


Software::Software() :bit_of_system("x64_and_x32")
{
}


void Software::output()
{
	std::cout <<"Name of program: "<< name << std::endl;
	std::cout <<"Bit of system: "<< bit_of_system << std::endl << std::endl;
}

Software::~Software()
{
}
