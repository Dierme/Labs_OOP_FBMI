#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Node
{
	Node *l, *r; 
	int data; 
	int level;
};

void add(int data, Node *&MyTree, int level) 
{
	if (NULL == MyTree)
	{
		MyTree = new Node; 
		MyTree->data = data; 
		MyTree->l = MyTree->r = NULL; 
		MyTree->level = level;
	}

	if (data<MyTree->data) 
	{
		if (MyTree->l != NULL) add(data, MyTree->l,level+1); 
		else
		{
			MyTree->l = new Node; 
			MyTree->l->l = MyTree->l->r = NULL; 
			MyTree->l->data = data; 
			MyTree->level = level;
			MyTree->l->level = level + 1;
		}
	}

	if (data>MyTree->data) 
	{
		if (MyTree->r != NULL) add(data, MyTree->r, level + 1); 
		else
		{
			MyTree->r = new Node; 
			MyTree->r->l = MyTree->r->r = NULL; 
			MyTree->r->data = data; 
			MyTree->level = level;
			MyTree->r->level = level + 1;
		}
	}
}

void Show(Node *&tree)
{
	if (NULL == tree) return; 
	cout << tree->data << " l=" << tree->l << " r=" << tree->r << "level= " << tree->level<< endl; //Посетили узел
	Show(tree->l);  
	Show(tree->r); 
}

void fDel(Node *tree)
{
	if (tree == NULL)
		return;
		fDel(tree->l);
		fDel(tree->r);
	delete tree;
}

void Remove(Node* pointer,Node*parent,int side, int level)  // side: 1 - left, 2 - right
{
	if  (level != pointer->level)
	{
		if (pointer->r != NULL)
			Remove(pointer->r,pointer,2, level);
		if (pointer->l != NULL)
			Remove(pointer->l, pointer,1, level);
	}

	if (pointer->level == level)
	{
		Node * removed = NULL;
		if (pointer->l == NULL && pointer->r == NULL)
		{
			removed = pointer;
			if (side == 1)
				parent->l = NULL;
			else
				parent->r = NULL;
			cout << removed->data<< " deleted" << endl;
			delete removed;
		}
	}
}

void main()
{
	int data,number,level; 
	cout << "Enter number of elements: ";
	cin >> number;
	cout << "Enter level for deleting leaves: ";
	cin >> level;

	Node *MyTree = NULL; 

	for (int i = 0; i<number; i++) 
	{
		cout << "data = "; cin >> data; 
		add(data, MyTree,1); 
	}
	Show(MyTree); 
	Remove(MyTree,NULL,0, level);
	fDel(MyTree);
	_getch();
}