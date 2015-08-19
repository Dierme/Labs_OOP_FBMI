#pragma once
#include <string>


class Software
{
public:
	Software();
	Software(std::string);
	virtual~Software();
	virtual void output();
protected:
	std::string name;
	std::string bit_of_system;
};

