#include "Artiodactyla.h"

void Artiodactyla ::setFamily(const string& familyIn)
{
	Family = familyIn;
}

void Artiodactyla ::setClan(const string& clanIn)
{
	Clan = clanIn;
}

void Artiodactyla ::setView(const string& viewIn)
{
	View = viewIn;
}


string Artiodactyla::getFamily() const
{
	return Family;
}

string Artiodactyla::getClan() const
{
	return Clan;
}

string Artiodactyla::getView() const
{
	return View;
}
Artiodactyla::Artiodactyla(const string& nameIn,const float weightIn ,const string& typeIn,const string&classIn,const string&subclassIn,const string&infraclassIn,const string&orderIn,
	const string&familyIn ,const string& clanIn,const string& viewIn)
	:Mammal(nameIn,weightIn,typeIn,classIn,subclassIn,infraclassIn,orderIn), Family(familyIn),Clan(clanIn),View(viewIn)
{	
}


Artiodactyla:: Artiodactyla()
{	
}

void Artiodactyla::show() 
{
	Mammal::show();
	cout<<"\n :"<<Family;
	cout<<"\n :"<<Clan;
	cout<<"\n :"<<View;
}
//---------------------------------------------------------
//ввід з клавіатури
void Artiodactyla::input()
{
	cout<<"\n Please input hierarchy of artiodactyla ";
	Mammal::input ();
	cout<<"\n Family:";
	fflush(stdin);
	getline(cin,Family);
	cout<<"\n Clan:";
	fflush(stdin);
	getline(cin,Clan);
	cout<<"\n View:";
	fflush(stdin);
	getline(cin,View);

}

ostream& operator<< (ostream &out, const Artiodactyla &animal)
{
	out << animal.Family << " ";
	out << animal.Clan << " ";
	out << animal.View << " ";
	return out;
}
 //---------------------------------------------------------
//перевантажений оператор >>
istream& operator>> (istream &in, Artiodactyla &animal)
{
	in.ignore(100,'\n');
	getline(in,animal.Family,'\t');
	getline(in,animal.Clan,'\t');
	getline(in,animal.View,'\t');
	return in;
}

Artiodactyla::~Artiodactyla()
{
}
