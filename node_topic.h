#pragma once
#include <iostream>
#include <string>
using namespace std;

class node_topic //Node Linked List Of Topic
{
public:
	string name;
	int importance;
	string S_T;
	node_topic* next;

	node_topic(string name, int importance, string S_T) {
		this->name = name;
		this->importance = importance;
		this->S_T = S_T;
		next = 0;

	}
};