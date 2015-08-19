#include "list.h"
#include<iostream>
using namespace std;

array_citizen::array_citizen()
{

}

void array_citizen::InitializeArray(int i)
{
	Array = new citizen[i];
}

void array_citizen::randomArrayFill(int pos)
{
	string ArrOfSurname[] = { "������", "�����������", "�������", "���������", "������", "������", "�����", "������", "�������", "������������" };
	string ArrOfName[] = { "����", "����������", "����������", "�����", "������", "����������", "����", "�������", "����", "�������" };
	string ArrOfMiddle_name[] = { "������������", "���������", "���������", "�������������", "��������", "����������", "���������", "���������", "��������", "��������" };
	string ArrOfEducation[] = { "�����", "�������", "�������������" };
	string  ArrOfSex[] = { "�������", "�������" };
	string ArrOfAddress[] = { "����", "�������", "������", "�������" };

	int k;
	int a = rand() % 9;
	int b = rand() % 3;
	if ((a = 2) || (a = 3) || (a = 10))  k = 0;
	else  k = 1;

	Array[pos].setSurname(ArrOfSurname[a]);
	Array[pos].setName(ArrOfName[a]);
	Array[pos].setMiddle_name(ArrOfMiddle_name[a]);
	Array[pos].setEducation(ArrOfEducation[b]);
	Array[pos].setAddress(ArrOfAddress[b]);
	Array[pos].setSex(ArrOfSex[k]);
	Array[pos].setYear_of_birth(1990 + rand() % 10);

}

void array_citizen::setArrayCitizen(int pos, citizen citizen)
{
	Array[pos].setSurname(citizen.getSurname());
	Array[pos].setName(citizen.getName());
	Array[pos].setMiddle_name(citizen.getMiddle_name());
	Array[pos].setEducation(citizen.getEducation());
	Array[pos].setAddress(citizen.getAddress());
	Array[pos].setSex(citizen.getSex());
	Array[pos].setYear_of_birth(citizen.getYear_of_birth());

}

citizen array_citizen::getArrayCitizen(int pos)
{
	return Array[pos];
}

void array_citizen::findAge(int currentyear, int numofyears, citizen a)
{
	int k = a.getYear_of_birth();
	if ((currentyear - k) > numofyears)
	{
		a.Output();
	}
}

void array_citizen::findEducation(int curreducation, citizen a)
{
	string k;
	if (curreducation == 1) k = "�����";
	if (curreducation == 2) k = "�������";
	if (curreducation == 3) k = "�������������";
	if (k.compare(a.getEducation()) == 0)
	{

		a.Output();
	}

}

void array_citizen::findSex(int needsex, citizen a)
{

	string k;
	if (needsex == 1) k = "�������";
	if (needsex == 0) k = "�������";
	else k = "ups";
	if (k.compare(a.getSex()) == 0)
	{
		a.Output();
	}


}

array_citizen::~array_citizen()
{
	delete[] Array;
}
