#include "citizen.h"
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;




citizen::citizen(string OutSurname, string OutName, string OutMiddle_name, string OutAddress, string OutEducation, string   OutSex, int OutYear_of_birth)
{
	Surname = OutSurname;
	Name = OutName;
	Middle_name = OutMiddle_name;
	Address = OutAddress;
	Education = OutEducation;
	Sex = OutSex;
	Year_of_birth = OutYear_of_birth;
}

void citizen::Output()
{

	setlocale(LC_ALL, "Russian");
	cout << "Фамилия:" << "\t" << Surname << endl;
	cout << "Имя:" << "\t" << Name << endl;
	cout << "Отчество:" << "\t" << Middle_name << endl;
	cout << "Адресс" << "\t" << Address << endl;
	cout << "Образование" << "\t" << Education << endl;
	cout << "Пол" << "\t" << Sex << endl;
	cout << "Год рождения" << "\t" << Year_of_birth << endl;
	cout << endl;

}

string citizen::getSurname() const
{
	return Surname;
}

string citizen::getName() const
{

	return Name;
}

string citizen::getMiddle_name() const
{
	return Middle_name;
}

string citizen::getAddress() const
{
	return Address;
}

string citizen::getEducation() const
{
	return Education;
}

string citizen::getSex() const
{

	return Sex;

}


int citizen::getYear_of_birth() const
{
	int b = Year_of_birth;
	return b;
}


void citizen::setSurname(string OutSurname)
{
	Surname = OutSurname;
}

void citizen::setName(string OutName)
{
	Name = OutName;
}

void citizen::setMiddle_name(string OutMiddle_name)
{
	Middle_name = OutMiddle_name;
}
void citizen::setAddress(string OutAddress)
{
	Address = OutAddress;
}

void citizen::setSex(string OutSex)
{
	Sex = OutSex;
}

void citizen::setEducation(string OutEducation)
{
	Education = OutEducation;
}

void citizen::setYear_of_birth(int OutYear_of_birth)
{
	Year_of_birth = OutYear_of_birth;
}


