#pragma once
#include<iostream>
#include <string>
#include "node_of_repated_topic.h"

using namespace std;

class  list_of_repated_topic
{
public:
	node_of_repated_topic* head;

	list_of_repated_topic() {
		this->head = NULL;
	}

	void insert(string name) {
		node_of_repated_topic* newnode = new node_of_repated_topic(name);
		if (head == 0)
		{
			newnode->next = head;
			head = newnode;
		}
		else
		{
			node_of_repated_topic* currentnode = head;
			while (currentnode->next != NULL)
			{
				currentnode = currentnode->next;
			}
			newnode->next = currentnode->next;
			currentnode->next = newnode;
		}
	}

	bool cheak(string name)
	{
		node_of_repated_topic* curNode = head;
		while (curNode != NULL && curNode->name != name)
		{
			curNode = curNode->next;
		}
		if (curNode)
			return true;
		else
			return false;
	}

	void cheak_of_exist(string name) {
		node_of_repated_topic* curNode = head;
		while (curNode != NULL && curNode->name != name)
		{
			curNode = curNode->next;
		}

		if (cheak(name))
		{
			curNode->appear++;
		}
		else
		{
			insert(name);
		}

	}

	void print() {
		node_of_repated_topic* curNode = head;

		while (curNode != NULL)
		{
			cout << curNode->name << "    " << curNode->appear << endl;
			curNode = curNode->next;
		}

	}

	void delete_by_name(string name)
	{
		node_of_repated_topic* currentnode = head;
		node_of_repated_topic* prenode = 0;
		if (currentnode->name == name) {
			head = currentnode->next;
			free(currentnode);

		}
		while (currentnode != 0 && currentnode->name != name) {
			prenode = currentnode;
			currentnode = currentnode->next;
		}
		if (currentnode != 0) {
			prenode->next = currentnode->next;
			free(currentnode);
		}
	}

	/*void filter() {
		node_of_repated_topic* curNode = head;
		node_of_repated_topic* temp;
		while (curNode != NULL)
		{
			if (curNode->appear < 2) {
				temp = curNode;
				curNode = curNode ->next;
				delete_by_name(temp);
			}
			else
				curNode = curNode->next;
		}
	}*/

};
