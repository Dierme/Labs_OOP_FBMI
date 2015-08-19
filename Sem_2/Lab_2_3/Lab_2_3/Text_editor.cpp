#include "Text_editor.h"
#include <iostream>


Text_editor::Text_editor(std::string name_inp,bool pdf_support_inp)
{
	name = name_inp;
	pdf_support = pdf_support_inp;
}


void Text_editor::output()
{
	std::cout << "Name of program: " << name << std::endl;
	std::cout << "Bit of system: " << bit_of_system << std::endl;
	if (pdf_support == true)
		std::cout << "Supports .pdf" << std::endl << std::endl;
	else
		std::cout << "Doesn't support .pdf" << std::endl << std::endl;
}

Text_editor::~Text_editor()
{
}
