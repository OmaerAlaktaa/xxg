#include<iostream>
#include <string>
using namespace std;
class God_Class
{
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
			while (curNode !=NULL)
			{
				if (curNode->appear < 2) {
					delete_by_name(curNode->name);
				}
				curNode = curNode->next;
			}

		}*/

	};

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

	class BST // Tree of Student
	{
	public:
		node_bst* root;
		BST() {
			root = NULL;
		}
		bool insert(node_bst newnode) {
			if (root == 0)
			{
				root = new node_bst(newnode);
				return true;
			}
			else {
				node_bst* q;
				node_bst* p;
				q = p = root;
				while (p != NULL)
				{
					q = p;
					if (p->stu.name > newnode.stu.name)
						p = p->left;
					else if (p->stu.name < newnode.stu.name)
						p = p->right;
					else
						return false;
				}
				if (q->stu.name > newnode.stu.name)
					q->left = new node_bst(newnode);
				else
					q->right = new node_bst(newnode);
				return true;
			}
		}

		void inorder(node_bst* bst)
		{
			if (bst != NULL)
			{
				inorder(bst->left);
				bst->stu.print();
				inorder(bst->right);
			}
			cout << endl;
		}

		void inorder_of_given_importance(node_bst* bst, int importance)
		{
			if (bst != NULL)
			{
				inorder_of_given_importance(bst->left, importance);
				bst->stu.print_of_given_importance(importance);
				inorder_of_given_importance(bst->right, importance);
			}
		}


		void traversal__(list_of_repated_topic& nd, node_bst* bst, string stuu)
		{
			if (bst != NULL)
			{
				traversal__(nd, bst->left, stuu);

				if (bst->stu.name == stuu)
				{
					bst->stu.lts.traversal_on_topics(nd);
				}
				traversal__(nd, bst->right, stuu);
			}
		}

		void find(string name_of_student, node_bst* curNode, string name_of_topic, int importance, string S_T)
		{
			//curNode = root;
			if (curNode == NULL)
				return;
			else if (name_of_student == curNode->stu.name)
				curNode->stu.lts.insert_topics(name_of_topic, importance, S_T);
			else if (name_of_student < curNode->stu.name)
				find(name_of_student, curNode->left, name_of_topic, importance, S_T);
			else
				find(name_of_student, curNode->right, name_of_topic, importance, S_T);
		}

		void print_more_than_given_age(node_bst* bst, int age)
		{
			if (bst != NULL)
			{
				print_more_than_given_age(bst->left, age);

				if (bst->stu.age > age)
				{
					cout << bst->stu.name << endl;;
				}
				print_more_than_given_age(bst->right, age);
			}

		}
		bool FindAndDeleteByMerging(string name)
		{
			if (root == 0)
				return false;
			node_bst* p = root, * parent = 0;
			while (p != 0)
			{
				if (p->stu.name == name)  break;
				parent = p;
				if (p->stu.name < name)  	p = p->right;
				else		p = p->left;
			}
			if (p == 0)
				return 0;
			if (parent == 0)  // node is the root
			{
				DelByMerge(root);
				return true;
			}
			if (parent->left == p)
				DelByMerge(parent->left);
			else
				DelByMerge(parent->right);
			return true;
		}

		void DelByMerge(node_bst*& q)
		{
			node_bst* p;
			if (q->left == 0)
			{
				p = q;
				q = q->right;
				delete p;
				return;
			}
			if (q->right == 0)
			{
				p = q;
				q = q->left;
				delete p;
				return;
			}
			p = q->left;
			while (p->right != 0)
				p = p->right;
			p->right = q->right;
			p = q;
			q = q->left;
			delete p;
		}

	};

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
};

class God_Class
{
};

