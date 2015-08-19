#include<iostream>
#include"Artiodactyla.h"
#include"Mammal.h"
#include"Animal.h"
#include"List.h"

void Run();
using namespace std;

void main()
{
	Run();
}
//---------------------------------------------------------
//функція створення парнокопитного 
void create_Artiodactyla(List &test) 
{
	Mammal *AR = new Artiodactyla();
	AR->input();
	test.push(AR);
}
//---------------------------------------------------------
//функція створення ссавця
void create_Mammal(List &test)
{
	Animal*MA=new Mammal();
	MA->input();
	test.push(MA);
}

void Run()
	{
		int i;
		List test;  //оголошення змінної списку
	do           // цикл повторення запита меню, доки не вказано вихід
	{
		system("cls");
		cout << "+------------- MENU -----------------+" << endl;
		cout << "|  [1] Create Mammal`s object        |" << endl;
		cout << "|  [2] Create Artiodactyl`s object   |" << endl;
		cout << "|  [3] Show the collection           |" << endl;
		cout << "|  [4] Remove the collection         |" << endl;
		cout << "|  [5] Remove the instanse           |" << endl;
		cout << "|  [6] Save to the file              |" << endl;
		cout << "|  [7] Load from the file            |" << endl;
		cout << "|  [8] Sort objects                  |" << endl;
		cout << "|  [9] Find the object               |" << endl;
		cout << "| [10] Do request                    |" << endl;
		cout << "| [11] Leave the program             |" << endl;
		cout << "+------------------------------------+" << endl << endl;
		cout << "[1-11]>";
		cin >> i;
		switch (i)
		{
		case 1:
		{
				  system("cls");
				  create_Mammal(test);
				  system("pause");
				  break;
		}
		case 2:
		{
				  system("cls");
				  create_Artiodactyla(test);
				  system("pause");
				  break;
		}
		case 3:
		{
				  system("cls");
				  test.Show_collection();
				  system("pause");
				  break;
		}
		case 4:
		{
				  system("cls");
				  test.Del_collection();
				  system("pause");
				  break;
		}
		case 5:
		{
				  system("cls");
				  test.Del_element();
				  system("pause");
				  break;
		}
		case 6:
		{
				  system("cls");
				  test.Save_to_file();
				  system("pause");
				  break;
		}
		case 7:
		{
				  system("cls");
				  test.Load_from_file();
				  system("pause");
				  break;
		}
		case 8:
		{
				  system("cls");
				  test.Sort_elements();
				  system("pause");
				  break;
		}
		case 9:
		{
				  system("cls");
				  test.Find_element();
				  system("pause");
				  break;
		}
		case 10:
		{
				   system("cls");
				   test.Do_request();
				   system("pause");
				   break;
		}
			
		default:
		{
				   if (i > 11 || i < 1)
				   {
					   cout << "Enter value from 1 to 11" << endl;
					   system("pause");
				   }
				   break;
		}
		}
	} while (i != 11);
}