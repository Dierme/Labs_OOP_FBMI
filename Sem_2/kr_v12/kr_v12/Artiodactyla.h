#pragma once
#include"Mammal.h"

class Artiodactyla: public Mammal
{
private:
	string Family;
	string Clan;
	string View;
public:
	void show() override; //���� �� ����� ����� �����
	void input()override; //��� � ��������� ������� �����
	void setFamily(const string&);
	void setClan(const string&);
	void setView (const string&);
	string getFamily() const;
	string getClan ()const;
	string getView()const;
	Artiodactyla(const string&,const float ,const string&,const string&,const string& ,const string&,const string&,
		const string&, const string& ,const string&);
	Artiodactyla();
	friend ostream& operator<< (ostream &out, const Artiodactyla &animal);
	friend istream& operator>> (istream &in, Artiodactyla &animal);
	~Artiodactyla();
};