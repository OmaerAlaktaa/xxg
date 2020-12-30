#include <iostream>
#include <string>
#include "node_topic.h"
#include "list_of_repated_topic.h"
using namespace std;

class list_of_topics //Linked List Of Topics
{
public:
	node_topic* head;

	list_of_topics()
	{
		head = NULL;
	}

	bool insert_topics(string name, int importance, string S_T) {
		node_topic* newnode = new node_topic(name, importance, S_T);
		if (head == 0) {
			newnode->next = head;
			head = newnode;
		}
		else
		{
			node_topic* currentnode = head;
			while (currentnode->next != NULL)
			{
				currentnode = currentnode->next;
			}
			newnode->next = currentnode->next;
			currentnode->next = newnode;

		}
		return true;
	}


	void print() {
		node_topic* currentnode = head;
		while (currentnode != NULL)
		{
			cout << "Name topic is : " << currentnode->name << "  It's importance : " << currentnode->importance << " S.T : " << currentnode->S_T << endl;
			currentnode = currentnode->next;
		}

	}
	void print_of_importance(int given_importance)
	{
		node_topic* currentnode = head;
		while (currentnode != NULL)
		{
			if (currentnode->importance < given_importance)
				cout << "Name topic is : " << currentnode->name << "  It's importance : " << currentnode->importance << " S.T : " << currentnode->S_T << endl;
			currentnode = currentnode->next;
		}
	}

	void traversal_on_topics(list_of_repated_topic& nd)
	{
		node_topic* currentnode = head;
		while (currentnode != NULL)
		{
			nd.cheak_of_exist(currentnode->name);
			currentnode = currentnode->next;
		}
	}
};