#pragma once
#include "Animal.h"


struct Node_of_list
{
	Node_of_list* Next;
	Animal* data;
};


class List
{
public:
	List(){Head = NULL; Tail = NULL;};
	~List();
	void push(Animal *);// ADD_ELEMENT to head// ADD_ELEMENT to tail
	void Show_collection();
	void Del_collection();
	void Del_element();
	void Find_element();
	void Do_request();
	void Sort_elements();
	void Save_to_file();
	void Load_from_file();
	string get_head() const;
	string get_tail() const;
private:
	Node_of_list* Head;
	Node_of_list* Tail;
};
