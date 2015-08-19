#pragma once
#include <string>

using namespace std; 

class Product abstract
{
private:
	string name;
	string type;

public:
	Product(string name, string type);

	void setName(string name);
	string getName() const;

	void setType(string type);
	string getType() const;

	virtual void print() abstract;
};