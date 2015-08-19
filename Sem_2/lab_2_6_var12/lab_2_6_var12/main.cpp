#include <iostream>
#include <list>
#include <conio.h>
#include "List.h"
#include "vld.h"
using namespace std;

int main()
{
	int n = 5; int t;
	List<int>*list_1 = new List<int>(n);
	cout << *list_1 << endl;
	list_1->insert_to_sorted_pos(n);
	list_1->Show_list();
	_getch();
	cout << "repetitions of element " << n << "= " << list_1->count_repetitions(5) << endl;
	_getch();

	List<int>*list_2 = new List<int>(n);
	*list_2 = *list_1;
	cout <<"list original: "<< *list_1 << endl;
	cout <<"list copy: "<< *list_2 << endl;
	_getch();
	delete list_1;
	delete list_2;
}