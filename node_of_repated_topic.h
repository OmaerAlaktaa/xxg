#pragma once
#include<iostream>
#include <string>

using namespace std;

class node_of_repated_topic
{
public:
	int appear; //The number of times to repeat topic
	string name;
	node_of_repated_topic* next;
	node_of_repated_topic(string name) {
		this->name = name;
		this->appear = 1;
		this->next = NULL;
	}

};