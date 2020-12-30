#include <iostream>
#include <string>
#include "student.h"
using namespace std;
class node_bst // Node Tree Of Student
{
public:
	node_bst* left;
	node_bst* right;
	student stu;

	node_bst(student stu) {
		this->stu = stu;
		left = right = NULL;
	}

};