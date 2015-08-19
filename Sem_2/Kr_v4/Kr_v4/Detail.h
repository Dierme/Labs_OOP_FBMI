#pragma once
#include "Product.h"
#include <string>

class Detail : public Product
{
private:
	string material;
	int weight;

public:
	Detail(string name, string type, string material, int weight);
	
	void setMaterial(string material);
	string getMaterial() const;

	void setWeight(int weight);
	int getWeight() const;

	void print();
};