#include "Mammal.h"
using namespace std;

void Mammal::setSubclass(const string& subclassIn)
{
	Subclass  = subclassIn;
}
void Mammal::setInfraclass(const string& infraclassIn)
{
	Infraclass = infraclassIn;
}
void Mammal::setOrder(const string& orderIn)
{
	Order  = orderIn;
}

string Mammal::getSubclass() const
{
	return Subclass;
}
string Mammal::getInfraclass() const
{
	return Infraclass;
}
string Mammal::getOrder() const
{
	return Order;
}
Mammal::Mammal(const string& nameIn,const float  weightIn ,const string& typeIn,const string&classIn,const string&subclassIn,const string&infraclassIn,const string&orderIn)
	:Animal(nameIn,weightIn,typeIn,classIn),Subclass(subclassIn),Infraclass(infraclassIn),
Order(orderIn)
{
}

Mammal::Mammal()
{
}
//-------------------------------------------------------
void Mammal::show() 
{
	Animal::show();
	cout<<"\n :"<<Subclass;
	cout<<"\n :"<<Infraclass;
	cout<<"\n :"<<Order;

}
//---------------------------------------------------------
//ввід з клавіатури
void Mammal::input()
{
	cout<<"\n Please input hierarchy of Mammal";
	cout<<"\n Name:";
	fflush(stdin);
	getline(cin,Name);
	cout<<"\n Weight:";
	fflush(stdin);
	cin>>Weight;
	cout<<"\n Type:";
	fflush(stdin);
	getline(cin,Type);
	cout<<"\n Class:";
	fflush(stdin);
	getline(cin,Class);
	cout<<"\n Subclass:";
	fflush(stdin);
	getline(cin,Subclass);
	cout<<"\n Infraclass:";
	fflush(stdin);
	getline(cin,Infraclass);
	cout<<"\n Order:";
	fflush(stdin);
	getline(cin,Order);
}

ostream& operator<< (ostream &out, const Mammal &animal)
{
	out<<animal.Name<<" ";
	out << animal.Weight << " ";
	out << animal.Type << " ";
	out << animal.Class << " ";
	out << animal.Subclass << " ";
	out << animal.Infraclass << " ";
	out<<animal.Order;
	return out;
}
 //---------------------------------------------------------
//перевантажений оператор >>
istream& operator>> (istream &in, Mammal &animal)
{
	in.ignore(100,'\n');
	getline(in,animal.Name,'\t');
	in>>animal.Weight;
	getline(in,animal.Type,'\t');
	getline(in,animal.Class,'\t');
	getline(in,animal.Subclass,'\t');
	getline(in,animal.Infraclass,'\t');
	getline(in,animal.Order,'\t');
	return in;
}
Mammal::~Mammal()
{
}
