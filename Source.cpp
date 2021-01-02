#include "God_Class.h"

using namespace std;

int main()
{
//Add list of topics
	list_of_topics l1;
	l1.insert_topics("Class", 10, "PR2");
	l1.insert_topics("class&pointer", 10, "ADS1");
	l1.insert_topics("Tkamoul", 4, "PS");
	l1.insert_topics("Register", 7, "Co");

	list_of_topics l2;
	l2.insert_topics("Class", 10, "DB1");
	l2.insert_topics("class&pointer", 10, "ADS1");
	l2.insert_topics("Tkamoul", 3, "CAL2");
	l2.insert_topics("NULL", 0, "EEC");

	list_of_topics l3;
	l3.insert_topics("Class", 10, "DB1");
	l3.insert_topics("class&pointer", 10, "ADS1");
	l3.insert_topics("Tkamoul", 3, "PS");
	l3.insert_topics("EN", 6, "ESP1");

	list_of_topics l4;
	l4.insert_topics("SQL", 10, "DB1");
	l4.insert_topics("class&pointer", 10, "ADS1");
	l4.insert_topics("Tkamoul", 3, "PS");
	l4.insert_topics("EN", 6, "ESP1");
	l4.insert_topics("CPU Arc", 7, "CA");

	list_of_topics l5;
	l5.insert_topics("SQL", 10, "DB2");
	l5.insert_topics("Automata", 4, "CTH");
	l5.insert_topics("Tkamoul", 3, "PS");
	l5.insert_topics("Digram", 6, "Sad");
	l5.insert_topics("Compiler Design", 7, "CD");

//Add student and give him the list of topics :
	student st1("Yasear", 201910274, 19, "Male", l1);
	student st2("Razan", 201920017, 19, "Female", l2);
	student st3("Omaer", 201910004, 20, "Male", l3);
	student st4("Zina", 201910005, 17, "Female", l4);
	student st5("Mamdouh", 201810862, 21, "Male", l5);

//Add student to semester :
	BST bst1;
	bst1.insert(st1);
	bst1.insert(st2);
	bst1.insert(st3);
	bst1.insert(st4);
	bst1.insert(st5);

//Add semester , Add student at  semester :
	semesters s1;
	s1.insert_sem("2020 spring", 100, 120, bst1);

//Function Test :
	s1.insert_topic("2020 spring", "Yasear", "Hacking", 10, "ISS");
	s1.insert_topic("2020 spring", "Razan", "Design", 10, "CG");
	s1.insert_topic("2020 spring", "Omaer", "App", 10, "CG");
	cout << "The student has old more than 19 : "; s1.print_more_than_given_age("2020 spring", 19);

//Print :
	cout << "------------------------------------This print before delete------------------------------------" << endl;
	s1.print();

//Delete Student :
	s1.delete_by_name("Zina");
	s1.delete_by_name("Mamdouh");
	cout << "------------------------------------This print after delete------------------------------------" << endl;
	s1.print();

	list_of_repated_topic lr1;
	s1.traversal(lr1, "Yasear");

	//lr1.filter();
	//lr1.print();

	system("pause");
}