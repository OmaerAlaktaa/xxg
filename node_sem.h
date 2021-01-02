#pragma once
#include <iostream>
#include <string>
#include "node_bst.h"
#include "BST.h"

using namespace std;

class node_sem //Node Linked List Of Semester
{
public:
	string name;
	int numb_of_stud;
	int period;
	node_sem* next;
	BST bst;

	node_sem(string name, int num_of_student, int period, BST bst)
	{
		this->name = name;
		this->numb_of_stud = numb_of_stud;
		this->period = period;
		this->bst = bst;
	}
};