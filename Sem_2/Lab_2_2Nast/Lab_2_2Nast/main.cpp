#include "list.h"
#include <stdio.h>
#include <iostream>
#include "conio.h"
#include <string>
using namespace std;


void main()
{
	int CurrYear;
	int NumberOfYears;
	int neededucation;
	int needsex;

	setlocale(LC_ALL, "Russian");

	array_citizen arr;
	arr.InitializeArray(10);

	for (int i = 0; i <= 9; i++)
	{
		arr.randomArrayFill(i);
	}


	cout << "¬ведите текущий год и необхожимый возраст жильца" << endl;
	cin >> CurrYear;
	cin >> NumberOfYears;

	cout << "∆ильцы возраст которых превышает заданый " << endl;
	for (int i = 0; i <= 9; i++)
	{
		arr.findAge(CurrYear, NumberOfYears, arr.getArrayCitizen(i));
	}



	cout << "¬ведите необходимое образование вишее-1 среднее-2 ,незаконченное-3" << endl;
	cin >> neededucation;
	cout << "∆ильцы с данным образованием " << endl;
	for (int i = 0; i <= 9; i++)
	{
		arr.findEducation(neededucation, arr.getArrayCitizen(i));
	}



	cout << "¬ведите необходимый пол(если мужчина- 1 ,если женшина-0)" << endl;
	cin >> needsex;
	for (int i = 0; i = 9; i++)
	{
		arr.findSex(needsex, arr.getArrayCitizen(i));
	}
	_getch();
}

