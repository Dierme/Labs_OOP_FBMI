#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


template <class user_class> struct Node
{
	user_class data;
	Node<user_class> *Next;
	Node<user_class> *Previous;
};


template <class user_class> class List
{
public:
	List();
	List(user_class);
	~List();
	user_class get_Tail() const;
	user_class get_Head() const;
	int get_size() const;
	void Add_elem(user_class x);
	int Count_number_of_elements();
	int Count_repetitions_of_element(user_class);
	bool Check_emptiness();
	void Show_list();
	void del_list();
	bool del_element(user_class);
	friend ostream& operator<<(ostream& os, const List& dt);
private:
	Node<user_class> *Head, *Tail;
	int size;
};


template <class user_class> bool check(int* x, int n, int k);
template <class user_class> bool check(Node<user_class>*, int);
template <class user_class> void inp(int* x, int n);
template <class user_class> int count_repetitions(Node<user_class>*, Node<user_class>*);


template <class user_class> int count_repetitions(Node<user_class>* list_1_head, Node<user_class>* list_2_head)
{
	int repetitions = 0;
	bool t;
	while (list_2_head != NULL)
	{
		t = check(list_1_head, list_2_head->data);

		if (!t)
			repetitions++;
		list_2_head = list_2_head->Next;
	}
	return repetitions;
}


template <class user_class> void inp(int* x, int n)
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


template <class user_class> bool check(int* x, int n, user_class rand)
{
	bool t = 0;
	for (int i = 0; i<n; i++)
	if (x[i] < rand)
		t = 1;
	return t;
}


template <class user_class> bool check(Node<user_class>*head, user_class k)
{
	Node<user_class> *temp = head;
	bool t = 1;
	while (temp != NULL)
	{
		if (temp->data == k)
		{
			t = 0;
			break;
		}

		temp = temp->Next;
	}
	return t;
}


template <class user_class> List<user_class>::List(user_class n) :Head(NULL), Tail(NULL), size(n)
{
	srand(time(NULL));
	user_class *array;
	array = new user_class[size];
	inp(array, size);
	for (int i = 0; i < size; i++)
	{
		Node<user_class> *temp = new Node<user_class>;
		temp->data = *(array + i);
		temp->Next = NULL;
		temp->Previous = NULL;

		if (Head != NULL)
		{
			temp->Previous = Tail;
			Tail->Next = temp;
			Tail = temp;

		}
		else
			Head = Tail = temp;
	}
	delete[] array;
}

template <class user_class> List<user_class>::List() :Head(NULL), Tail(NULL){}

template <class user_class>
List<user_class>::~List(){}


template <class user_class> ostream& operator <<(ostream& os, const List<user_class>& dt)
{
	Node<user_class> *temp = dt.Head;
	while (temp != NULL)
	{
		os << std::setw(4) << temp->data;
		temp = temp->Next;
	}
	os << std::endl;
	return os;
}


template <class user_class> int List<user_class>::get_size() const
{
	return size;
}


template <class user_class> void List <user_class>::Add_elem(user_class element_inp)
{
	size++;
	Node<user_class> *new_elem_node = new Node<user_class>;
	new_elem_node->data = element_inp;
	new_elem_node->Next = NULL;
	new_elem_node->Previous = NULL;

	Node<user_class> *temp_list = Head;

	while (temp_list != NULL)
	{
		if (element_inp > temp_list->data)
		{
			if (temp_list == Head)
			{
				temp_list->Previous = new_elem_node;
				new_elem_node->Next = temp_list;
				Head = new_elem_node;
				break;
			}

			temp_list->Previous->Next = new_elem_node;
			new_elem_node->Previous = temp_list->Previous;
			new_elem_node->Next = temp_list;
			temp_list->Previous = new_elem_node;
			break;
		}

		if ((temp_list == Tail) && (element_inp < temp_list->data))
		{
			temp_list->Next = new_elem_node;
			new_elem_node->Previous = temp_list;
			break;
		}
		temp_list = temp_list->Next;
	}
}

template <class user_class> void List<user_class>::Show_list()
{
	Node<user_class> *temp = Head;
	while (temp != NULL)
	{
		std::cout << std::setw(4) << temp->data;
		temp = temp->Next;
	}
	std::cout << std::endl;
}

template <class user_class> void List<user_class>::del_list()
{
	Node<user_class> *temp = Head;
	while (temp != NULL)
	{
		temp = Head->Next;
		delete Head;
		Head = temp;
	}
}


template <class user_class> bool List<user_class>::Check_emptiness()
{
	return Head == NULL ? true : false;
}


template <class user_class> int List<user_class>::Count_number_of_elements()
{
	Node<user_class>*temp = Head;
	int number_of_elements = 0;
	while (temp != NULL)
	{
		number_of_elements++;
		temp = temp->Next;
	}
	return number_of_elements;
}


template <class user_class> int List<user_class>::Count_repetitions_of_element(user_class element_inp)
{
	Node<user_class>*temp = Head;
	int repetitions_of_element = 0;
	while (temp != NULL)
	{
		if (element_inp == temp->data)
		{
			repetitions_of_element++;
		}

		temp = temp->Next;
	}
	return repetitions_of_element;
}


template <class user_class> user_class List<user_class>::get_Tail() const
{
	return Tail->data;
}


template <class user_class> user_class List<user_class>::get_Head() const
{
	return Head->data;
}


template <class user_class> bool List<user_class>::del_element(user_class element)
{
	Node<user_class>*temp = Head;
	Node<user_class>*temp_prev;
	Node<user_class>*temp_next;
	bool t = 0;
	while (temp != NULL)
	{
		temp_prev = temp->Previous;
		temp_next = temp->Next;
		if (temp->data == element)
		{
			if (temp == Tail)
			{
				temp_prev->Next = NULL;
				t = 1;
				delete temp;
				break;
			}

			temp_prev->Next = temp_next;
			temp_next->Previous = temp_prev;
			delete temp;
			t = 1;
			break;
		}
		temp = temp->Next;
	}
	return t;
}