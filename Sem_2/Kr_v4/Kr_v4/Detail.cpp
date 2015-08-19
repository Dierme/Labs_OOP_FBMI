#include "Detail.h"
#include <iostream>

using namespace std;

Detail::Detail(string name, string type, string material, int weight) : Product(name, type)
{
	setMaterial(material);
	setWeight(weight);
}

void Detail::setMaterial(string material)
{
	this->material = material;
}

string Detail::getMaterial() const
{
	return material;
}

void Detail::setWeight(int weight)
{
	this->weight = weight;
}

int Detail::getWeight() const
{
	return weight;
}

void Detail::print()
{
	cout << "[Name] " << getName() << endl;
	cout << "[Type] " << getType() << endl;	
	cout << "[Material] " << getMaterial() << endl;
	cout << "[Weight] " << getWeight() << endl << endl;
}