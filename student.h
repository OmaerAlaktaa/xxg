#pragma once
#include <iostream>
#include <string>
#include "node_topic.h"
#include "list_of_topics.h"
using namespace std;

class student
{
public:
	string name;
	int age;
	int id;
	string gender;
	list_of_topics lts;
	student() {
		this->name = "  ";
		this->age = -1;
		this->gender = "unknow";

	}


	student(string name, int id, int age, string gender, list_of_topics lts) {
		this->name = name;
		this->age = age;
		this->id = id;
		this->gender = gender;
		this->lts = lts;
	}
	void print() {
		cout << this->name << "\t" << this->id << "\t" << this->age << "\t" << this->gender << endl;
		lts.print();
	}

	void print_of_given_importance(int importance) {
		cout << this->name << "\t" << this->id << "\t" << this->age << "\t" << this->gender << endl;
		lts.print_of_importance(importance);
	}

};