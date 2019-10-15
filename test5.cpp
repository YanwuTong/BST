//test5.cpp
//test the delete function 

#include "stree.h"
#include <iostream>

using namespace std;

int main(){

	stree s;
	stree t1, t2;

	s.root = new node(6);
	s.root->left = new node(4);
	s.root->left->parent = s.root;
	s.root->right = new node(8);
	s.root->right->parent = s.root;
	s.root->left->right = new node(5);
	s.root->left->right->parent = s.root->left;
	s.root->left->left = new node(2);
	s.root->left->left->parent = s.root->left;
	s.root->right->left = new node(7);
	s.root->right->left->parent = s.root->right;
	s.root->right->right = new node(10);
	s.root->right->right->parent = s.root->right;

	s.print(s.root, 1);
	cout << endl;
	s.print(s.root, 2);
	cout << endl;
	s.print(s.root, 3);
	cout << endl;
	s.print(s.root, 4);
	cout << endl;
	s.print(s.root, 5);
	cout << endl;

	s.delet(6, t1, t2);

	s.print(s.root, 1);
	cout << endl;
	s.print(s.root, 2);
	cout << endl;
	s.print(s.root, 3);
	cout << endl;
	s.print(s.root, 4);
	cout << endl;
	s.print(s.root, 5);
	cout << endl;

}