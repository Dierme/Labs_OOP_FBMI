#pragma once
#include "Animal.h"
using namespace std;

class Mammal: public Animal
{
private:
	string Subclass;
	string Infraclass;
	string Order;
public:
	void show() override; //вивід на екран вмісту плей
	void input() override; //ввід з клавіатури значень полей
	void setSubclass(const string&);
	void setInfraclass(const string&);
	void setOrder(const string&);
	string   getSubclass() const;
	string   getInfraclass() const;
	string   getOrder() const;
	Mammal(const string&,const float  ,const string&,const string&,const string& ,const string&,const string&);
	Mammal();
	friend ostream& operator<< (ostream &out, const Mammal &animal);
	friend istream& operator>> (istream &in, Mammal &animal);
	~Mammal();
};