#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <string.h>
#include <iostream>

using namespace std;

Student::Student(char*Full_Name_inp, char*Place_Of_birth_inp, char*Adress_inp, char*Education_inp, 
	char* Date_of_birth_inp, char*gender_inp,int age_inp, int* number)
{
	*number = *number+1;
	Student::key = *number;

	Full_Name_size = strlen(Full_Name_inp) + 1;
	Full_Name = new char [Full_Name_size];
	strcpy(Full_Name, Full_Name_inp);

	Place_Of_birth_size = strlen(Place_Of_birth_inp) + 1;
	Place_Of_birth = new char[Place_Of_birth_size];
	strcpy(Place_Of_birth, Place_Of_birth_inp);

	Adress_size = strlen(Adress_inp) + 1;
	Adress = new char[Adress_size];
	strcpy(Adress, Adress_inp);

	Education_size = strlen(Education_inp) + 1;
	Education = new char [Education_size];
	strcpy(Education, Education_inp);

	Date_Of_birth_size = strlen(Date_of_birth_inp) + 1;
	Date_Of_birth = new char[Date_Of_birth_size];
	strcpy(Date_Of_birth, Date_of_birth_inp);

	gender_size = strlen(gender_inp) + 1;
	gender = new char[gender_size];
	strcpy(gender, gender_inp);

	age = age_inp;
}


Student::Student(int* number)
{
	*number = *number + 1;
	Student::key = *number;
}

Student::~Student()
{
	delete[] Full_Name;
	delete[] Place_Of_birth;
	delete[] Adress;
	delete[] Education;
	delete[] Date_Of_birth;
	delete[] gender;
}

void Student::set_Full_Name(char* Full_Name_inp)
{
	int len = strlen(Full_Name_inp) + 1;
	if (len > Full_Name_size)
	{
		delete[] Full_Name;
		Full_Name = new char[len];
		Full_Name_size = len;
		strcpy(Full_Name, Full_Name_inp);
	}
	else
		strcpy(Full_Name, Full_Name_inp);
}

void Student::set_gender(char* gender_inp)
{
	int len = strlen(gender_inp) + 1;
	if (len > gender_size)
	{
		delete[] gender;
		gender = new char[len];
		gender_size = len;
		strcpy(gender, gender_inp);
	}
	else
		strcpy(gender, gender_inp);
}

void Student::set_age(int age_inp)
{
	age = age_inp;
}

void Student::set_Place_Of_birth(char* Place_Of_birth_inp) 
{
	int len = strlen(Place_Of_birth_inp) + 1;
	if (len > Place_Of_birth_size)
	{
		delete[]  Place_Of_birth;
		Place_Of_birth = new char[len];
		Place_Of_birth_size = len;
		strcpy(Place_Of_birth, Place_Of_birth_inp);
	}
	else
		strcpy(Place_Of_birth, Place_Of_birth_inp);
}

void Student::set_Adress(char* Adress_inp) 
{
	int len = strlen(Adress_inp) + 1;
	if (len >Adress_size)
	{
		delete[]  Adress;
		Adress = new char[len];
		Adress_size = len;
		strcpy(Adress, Adress_inp);
	}
	else
		strcpy(Adress, Adress_inp);
}

void Student::set_Date_Of_birth(char* Date_Of_birth_inp) 
{
	int len = strlen(Date_Of_birth_inp) + 1;
	if (len > Date_Of_birth_size)
	{
		delete[]  Date_Of_birth;
		Date_Of_birth = new char[len];
		Date_Of_birth_size = len;
		strcpy(Date_Of_birth, Date_Of_birth_inp);
	}
	else
		strcpy(Date_Of_birth, Date_Of_birth_inp);
}

void Student::set_Education(char* Education_inp)
{
	int len = strlen(Education_inp) + 1;
	if (len > Education_size)
	{
		delete[]  Education;
		Education = new char[len];
		Education_size = len;
		strcpy(Education, Education_inp);
	}
	else
		strcpy(Education, Education_inp);
}

void Student::show_citizen(void)
{
	cout << "Number:" << key << endl;
	cout << "Name:" << Full_Name << endl;
	cout << "Sex:" << gender << endl;
	cout << "Age:" << age << endl;
	cout << "Adress:" << Adress << endl;
	cout << "Place_Of_birth:" << Place_Of_birth << endl;
	cout << "Date_of_birth:" << Date_Of_birth << endl;
	cout << "Education:" << Education << endl;

}

int Student::get_age()
{
	return age;
}

int Student::get_edu() 
{
	if (Education == "High")
		return 1;
	else return 0;
}

int Student::get_gender()
{
	if (gender == "Male")
		return 1;
	else return 0;
}
