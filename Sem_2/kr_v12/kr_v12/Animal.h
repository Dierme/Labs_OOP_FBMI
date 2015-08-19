/*Стаховская А.І
Бс-32*/
#pragma once
#include<iostream>
#include<string>
using namespace std;

 class Animal abstract
 {
 protected :
	 string Name;
	 float Weight;
	 string Type;
	 string Class;
 public:
	 virtual void input();
	 virtual void show() ;
	 virtual float count_avarage_weight(){return 0;} //вкинеш ревлізацію в срр
	void setName(const string&);
	void setType(const string&);
	void setClass(const string&);
	void setWeight(const float );
	string getName() const;
	string getType() const;
	string getClass() const;
	float getWeight() const;
	Animal(const string&, const float,const string&,const string&);
	Animal();
	virtual ~Animal();
 };