#include "Product.h"

Product::Product(string name, string type)
{
	setName(name);
	setType(type);
}

void Product::setName(string name)
{
	this->name = name;
}

string Product::getName() const
{
	return name;
}

void Product::setType(string type)
{
	this->type = type;
}

string Product::getType() const
{
	return type;
}
