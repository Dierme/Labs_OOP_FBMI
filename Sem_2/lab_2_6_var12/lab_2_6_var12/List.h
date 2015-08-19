#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <ostream>
#include <list>

using namespace std;


template <class user_class>
class List
{
public:
	List();
	List(int);
	List(const List&);
	void Show_list() const;
	~List(){ cout << "d-tor" << endl; _getch();  delete list_stl; };
	list<user_class>* get_list() const;	
	int get_size() const;
	void add_element(user_class);
	bool empty();
	void clear();
	void insert_to_sorted_pos(user_class);
	void remove(user_class);
	int count_repetitions(user_class);
	List<user_class>& operator = (List<user_class> &obj);
	friend ostream& operator<<<user_class>(ostream&, const list<user_class>&);
private:
	std::list<user_class>* list_stl; 
};


template <class user_class> bool check(int* x, int n, int k);
template <class user_class> void inp(user_class* x, int n);


//Конструктор
template <class user_class>
List<user_class>::List(int n) : list_stl(NULL)
{
	srand(time(NULL));
	list_stl = new std::list<user_class>;
	user_class *array;
	array = new user_class[n];
	inp(array, n);
	for (int i = 0; i < n; i++)
		list_stl->push_back(*(array + i));
	delete[] array;
}
//--------------------------------------------------------------------


//Конструктор копирования
template <class user_class>
List<user_class>::List(const List& obj)
{
	obj.list_stl = new list<user_class>;
	std::list<user_class>::iterator it;
	for (it = list_stl->begin(); it != list_stl->end(); it++)
	{
		obj.list_stl->push_back(*it);
	}
}
//--------------------------------------------------------------------


//Operator <<
template <class user_class>
ostream& operator <<(ostream& os, const List<user_class>& dt)
{
	cout << "operator << ";
	std::list<user_class>* list_stl = dt.get_list();
	std::list<user_class>::iterator it;
	for (it = list_stl->begin(); it != list_stl->end(); ++it)
		os << std::setw(4) << *it;
	os << std::endl;
	return os;
}
//--------------------------------------------------------------------


////Operator =
template <class user_class>
List<user_class>& List<user_class>::operator=(List<user_class> &obj)
{
	if (list_stl != NULL)
	{
		delete list_stl;
		list_stl = NULL;
	}

	list_stl = new list<user_class>;
	std::list<user_class>::iterator it;
	for (it = obj.list_stl->begin(); it != obj.list_stl->end(); it++)
	{
		list_stl->push_back(*it);
	}
	return *this;
}
//--------------------------------------------------------------------

template <class user_class>
int List<user_class> ::count_repetitions(user_class inp_elem)
{
	int repetitions = 0;
	std::list<user_class>::iterator it;
	for (it = list_stl->begin(); it != list_stl->end(); it++)
	{
	
		if (inp_elem == *it)
			repetitions++;
	}
	return repetitions;
}


template <class user_class>
void List<user_class>::add_element(user_class inp_x)
{
	list_stl->push_front(inp_x);
}
//--------------------------------------------------------------------

template <class user_class>
bool List<user_class>::empty()
{
	return list_stl->empty();
}
//--------------------------------------------------------------------


template <class user_class>
void List<user_class>::clear()
{
	list_stl->clear();
}
//--------------------------------------------------------------------


template <class user_class>
void List<user_class>::remove(user_class rem_x)
{
	list_stl->remove(rem_x);
}
//--------------------------------------------------------------------


template <class user_class>
int List<user_class>::get_size() const
{
	return list_stl->size();
}
//--------------------------------------------------------------------


template <class user_class>
void List<user_class>::insert_to_sorted_pos(user_class element)
{
	cout << "Insert to position elem ("<<element<<"): ";
	user_class list_stl_elem;
	std::list<int>::iterator it = list_stl->begin();
	for (it; it != list_stl->end(); it++)
	{
		list_stl_elem = *it;
		if (element > list_stl_elem)
		{
			list_stl->insert(it, element);
			return;
		}
	}
	list_stl->insert(it, element);
}

template <class user_class>
void inp(user_class* x, int n)
{
	srand(time(NULL));
	user_class rand_value;
	bool t;
	for (int i = 0; i<n; i++)
	{
		if (i == 0)
			rand_value = rand() % 500;
		else
		{
			t = 1;
			while (t)
			{
				rand_value = rand() % 100;
				t = check(x, i, rand_value);
			}
		}
		x[i] = rand_value;
	}
}


template <class user_class>
bool check(int* x, int n, user_class rand)
{
	bool t = 0;
	for (int i = 0; i<n; i++)
	if (x[i] < rand)
		t = 1;
	return t;
}


template <class user_class> bool check( user_class k)
{
	node<user_class> *temp = head;
	bool t = 1;
	while (temp != null)
	{
		if (temp->data == k)
		{
			t = 0;
			break;
		}

		temp = temp->next;
	}
	return t;
}


template <class user_class>
std::list<user_class>* List<user_class>::get_list() const
{
	return  list_stl;
}


//Конструктор за замовчанням
template <class user_class>
List<user_class>::List() : list_stl(NULL)
{

}
//--------------------------------------------------------------------
//
//
//Показати список
template <class user_class> void List<user_class>::Show_list() const
{
	cout << "Show List: ";
	std::list<int>::iterator it;
	it =  list_stl->begin();
	for (it ; it != list_stl->end(); ++it)
		std::cout << " " << *it; 
	cout << endl;
	
	return;
}
//--------------------------------------------------------------------


