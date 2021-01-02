#pragma once
#include <iostream>
#include <string>
#include "node_bst.h"


using namespace std;

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