#include <iostream>
#include <string>
#include "node_sem.h"
using namespace std;

class semesters // Linked List Of Semesters
{
public:
	node_sem* head;
	semesters() {
		head = NULL;
	}

	bool insert_sem(string name, int num_of_student, int period, BST bst)
	{
		node_sem* newnode = new node_sem(name, num_of_student, period, bst);
		if (head == 0) {
			newnode->next = head;
			head = newnode;
		}
		else
		{
			node_sem* currentnode = head;
			while (currentnode->next != NULL)
			{
				currentnode = currentnode->next;
			}
			newnode->next = currentnode->next;
			currentnode->next = newnode;
			print();
		}
		return true;
	}
	void insert_topic(string name_of_sem, string name_of_student, string name_of_topic, int importance, string S_T) {
		node_sem* curNode = head;
		while (curNode->next != NULL, curNode->name != name_of_sem)
		{
			curNode = curNode->next;
		}
		if (curNode)
			curNode->bst.find(name_of_student, curNode->bst.root, name_of_topic, importance, S_T);

	}

	void print() {
		node_sem* curNode = head;

		while (curNode != NULL)
		{
			curNode->bst.inorder(curNode->bst.root);
			curNode = curNode->next;
		}
	}


	void print_of_importance(int given_importance) {
		node_sem* curNode = head;

		while (curNode != NULL)
		{
			curNode->bst.inorder_of_given_importance(curNode->bst.root, given_importance);
			curNode = curNode->next;
		}
	}



	void print_more_than_given_age(string semester, int age) {
		node_sem* curNode = head;
		while (curNode != NULL)
		{
			if (curNode->name == semester) {
				curNode->bst.print_more_than_given_age(curNode->bst.root, age);
			}
			curNode = curNode->next;
		}
	}

	void delete_by_name(string name) {
		node_sem* curNode = head;
		while (curNode != NULL)
		{
			curNode->bst.FindAndDeleteByMerging(name);
			curNode = curNode->next;
		}

	}

	void traversal(list_of_repated_topic& list, string student) {
		node_sem* curNode = head;

		while (curNode != NULL)
		{
			curNode->bst.traversal__(list, curNode->bst.root, student);

			curNode = curNode->next;
		}

	}

};