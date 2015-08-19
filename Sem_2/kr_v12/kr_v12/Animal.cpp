/*Стаховская А.І
Бс-32*/
#include "Animal.h"
#include<iostream>

void Animal::show()
{
	cout<<"\n :"<<Name;
	cout<<"\n :"<<Weight;
	cout<<"\n :"<<Type;

}
void Animal::setName(const string& nameIn)
{
	Name = nameIn;
}

void Animal::setWeight(const float weightIn)
{
	Weight=weightIn;
}

void Animal::setType(const string& typeIn)
{
	Type  = typeIn;
}

void Animal::setClass(const string& classIn)
{
	Class = classIn;
}

string Animal::getName() const
{
	return Name;
}

float Animal::getWeight() const 
{
	return Weight;
}

string Animal::getType() const
{
	return Type;
}

string Animal::getClass() const
{
	return Class;
}

Animal::Animal(const string& nameIn,const float weightIn,const string&typeIn,const string& classIn)
	:Name(nameIn),Weight(weightIn),Type(typeIn), Class(classIn)
{
}
Animal::Animal()
{
}
void Animal::input()
{
}



Animal::~Animal(void)
{
}