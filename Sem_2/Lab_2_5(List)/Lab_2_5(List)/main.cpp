#include <iostream>
#include <conio.h>
#include "Header.h"
#include "vld.h"

using namespace std;

void main()
{
	int size = 5;
	int elem_1 = 20;
	int elem_2 = 11;
	List <int>* list_1 = new List<int>(size);
	list_1->Show_list();
	cout<< "Number of elements = " <<list_1->Count_number_of_elements()<< endl;
	cout << "Number of repetitions of element (0) = " << list_1->Count_repetitions_of_element(0) <<endl;
	cout << list_1->get_Head() << " (head), " << list_1->get_Tail() << " (tail)";
	list_1->Add_elem(elem_1); cout << endl;
	list_1->Show_list();
	_getch();

	bool t;
	t = list_1->del_element(elem_1);
	if (t)
		cout << "Element (" << elem_1 << ") has been succesfully deleted." << endl;
	else
		cout << "There's no such element (" << elem_1 << ") in the list." << endl;
	list_1->Show_list();

	t = list_1->del_element(elem_2);
	if (t)
		cout << "Element (" << elem_2 << ") has been succesfully deleted." << endl;
	else
		cout << "There's no such element (" << elem_2 << ") in the list." << endl;

	list_1->Show_list();
	_getch();

	cout << list_1;
	_getch();
	list_1->del_list();
}