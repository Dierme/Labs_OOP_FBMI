#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include "Animal.h"
#include "Artiodactyla.h"
#include "Mammal.h"
#include "List.h"
#include <typeinfo.h>
#include <fstream>

using namespace std;
//------------------------------------------------------------------------------------
List::~List()
{
	Del_collection();
}
//------------------------------------------------------------------------------------

string List::get_head() const
{
	return Head->data->getName();
}

//------------------------------------------------------------------------------------

string List::get_tail() const
{
	return Tail->data->getName();
}
//------------------------------------------------------------------------------------
void List::push(Animal*data)
{
	Node_of_list * new_element= new Node_of_list;
	new_element->data=data;
	new_element->Next=NULL;
	if (Head==NULL)
	{
		Head=new_element;
		Tail = Head;
		Head->Next=NULL;
		cout<<"element is added"<<endl;
	}
	else
	{	
		new_element->Next=Head;
		Head=new_element;
		cout<<"element is added"<<endl;
	}

}

//------------------------------------------------------------------------------------

void List::Show_collection()
{
	//перевірка на порожність списку
	if (Head == NULL)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	Animal* ptrAnimal;
	Node_of_list *temp = Head;
	while (temp != NULL)				// з елементу Head до останнього елементу
	{
		ptrAnimal = temp->data;
		std::cout << std::setw(4);		// виводимо дані списку
		ptrAnimal->show(); cout << endl;
		temp = temp->Next;				// переходимо на наступний елемент
	}
	std::cout << std::endl;

	cout << "Head: " << get_head() << endl;
	cout << "Tail: " << get_tail() << endl;
}

//------------------------------------------------------------------------------------

void List::Del_collection()
{
	//перевірка на порожність списку
	if (Head == NULL)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	Node_of_list *temp = Head;
	while (temp != NULL)		// з елементу Head до останнього елементу
	{
		temp = Head->Next;		// переходимо на наступний елемент
		delete Head->data;		// видаляємо дані елементу списка
		delete Head;			// видаляємо звено списку
		Head = temp;			// ініціалізуємо початок списку наступним елементом
	}
	cout << "Collection has been removed successfully!";
}


//------------------------------------------------------------------------------------

void List::Del_element()
{
	//перевірка на порожність списку
	if (Head == NULL)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	string animal;
	cout << "What animal would you like to remove from the collection? "; cin >> animal;

	Node_of_list*temp = Head->Next;
	Node_of_list* previous_elem = Head;

	//якщо шуканий елемент це Head, то потрібно змінити початок списку 
	if (animal == Head->data->getName())
	{
		delete Head->data;		// видаляємо дані елементу списка
		delete Head;			// видаляємо звено списку
		Head = temp;			// змінюємо початок списку
		cout << "Element <" << animal << "> (Head) has been succesfully deleted!" << endl;
		return;
	}

	while (temp != NULL)
	{
		//якщо шуканий елемент це Tail, то потрібно змінити кінець списку 
		if (animal == Tail->data->getName())
		{
			delete Tail->data;		// видаляємо дані елементу списка
			delete Tail;			// видаляємо звено списку
			Tail = previous_elem;	// змінюємо кінцець списку
			Tail->Next = NULL;
			cout << "Element <" << animal << ">(Tail) has been succesfully deleted!" << endl;
			return;
		}

		//видаляємо елемент в середені списку
		if (animal == temp->data->getName())
		{
			previous_elem->Next = temp->Next;
			delete temp->data;
			delete temp;
			cout << "Element <" << animal << "> has been succesfully deleted!" << endl;
			_getch();
			return;
		}
		previous_elem = temp;
		temp = temp->Next;
	}
	cout << "There is no such element!" << endl;
	return;
}

//------------------------------------------------------------------------------------

void List::Find_element()
{
	//перевірка на порожність списку
	if (Head == NULL)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	string animal;
	cout << "What animal would you like to display from the collection? "; cin >> animal;

	Node_of_list*temp = Head;

	while (temp != NULL)
	{
		if (animal == temp->data->getName())
		{
			temp->data->show();
			_getch();
			return;
		}
		temp = temp->Next;
	}
	cout << "There is no such element!" << endl;
	return;
}

//------------------------------------------------------------------------------------
//вивести на екран вагу найважчого парнокопитного з колекції
void List::Do_request()
//перевірка на порожність списку
{
	if (Head == NULL)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	Node_of_list*temp = Head;
	float max_average_weight = NULL;
	Artiodactyla *ptrArtiodactyla;
	string max_name;
	int k = 0;

	while (temp != NULL)
	{
		ptrArtiodactyla = dynamic_cast<Artiodactyla*>(temp->data);
		if (ptrArtiodactyla != NULL)
		{
			k++;	// коли знаходимо парнокопитне, k стає відмінне від нуля
			//визначаємо максимальну вагу серед парнокопитних
			if (max_average_weight < temp->data->getWeight())
			{
				max_name = temp->data->getName();
				max_average_weight = temp->data->getWeight();
			}
		}
		temp = temp->Next; // переходимо на наступний елемент
	}

	if (k == 0)
	{
		cout << "There are no artiodactyl animals in the list" << endl;
		return;
	}
	else
	{
		cout << "Max average weight between artiodactyls belongs to " << max_name << " (" << max_average_weight << ")" << endl;
	}
	return;
}

//------------------------------------------------------------------------------------
// сортування елементів за максимальною вагаю методом пузирчика
void List::Sort_elements()
//перевірка на порожність списку

{
	if (Head == NULL)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	bool exit = false;			//вихід з циклу сортування
	Node_of_list *temp = Head;

	while (!exit)
	{
		exit = true;
		while (temp != Tail)	//початок циклу сорування
		{
			float temp_Weight = temp->data->getWeight();
			float tempNext_Weight = temp->Next->data->getWeight();

			// обмін елементів місцями,
			// якщо в першому елементі тривалість життя більше, ніж в другому
			if (temp_Weight >tempNext_Weight)
			{
				Animal* ptr_data;
				ptr_data = temp->data;
				temp->data = temp->Next->data;
				temp->Next->data = ptr_data;
				exit = false; //виходу з циклу не буде, бо був здійснений обмін
			}
			temp = temp->Next;
		}
		temp = Head;
	}
	return;
}
//---------------------------------------------------------
void List::Save_to_file()
{
	if (Head == NULL)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	ofstream out("Animals.txt");
	if (!out.is_open())
	{
		cout << "Error. Can not open file for output." << endl << endl;
		return;
	}

	cout << "Saving. . ."<<endl;
	Node_of_list *temp = Head;
	do
	{
		if (dynamic_cast<Artiodactyla*>(temp->data))
		{
			out << "Artiodactyla" << endl;
			out << *(dynamic_cast<Artiodactyla*>(temp->data));
		}

		if (dynamic_cast<Mammal*>(temp->data))
		{
			out << "Mammal" << endl;
			out << *(dynamic_cast<Mammal*>(temp->data));
		}

		temp = temp->Next;
	} 
	while (temp != NULL);
}
void List::Load_from_file()
{
	ifstream in("Animals.txt");
	if (!in.is_open())
	{
		cout << "Error. Can not open file for input." << endl << endl;
		return;
	}
	cout << "Loading. . ."<<endl;
	Animal* ptr_animal;
	string k = "0";
	while (!in.eof())
	{
		getline(in, k);

		if (k == "Mammal")
		{
			ptr_animal = new Mammal();
			in >> *(dynamic_cast<Mammal*>(ptr_animal));
			push(ptr_animal);
		}

		if (k == "Artiodactyla")
		{		
			ptr_animal = new Artiodactyla();
			in >> *(dynamic_cast<Artiodactyla*>(ptr_animal));
			push(ptr_animal);
		}
	}
}