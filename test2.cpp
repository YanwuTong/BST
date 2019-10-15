//test1.cpp

//tests for double rotation for the same sides

#include "stree.h"
#include <iostream>

using namespace std;

int main(){

	stree s;

	s.root = new node(6);
	node* p = new node(5);
	s.root->left = p;
	p->parent = s.root;
	node* a = new node(3);
	p->left = a;
	a->parent = p;
	node* b = new node(2);
	a->left = b;
	b->parent = a;
	node* c = new node(1);
	b->left = c;
	c->parent = b;




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

	cout << "-------" << endl;

	s.access(1);

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

	cout << "-------" << endl;

	// s.access(6);

	// s.print(s.root, 1);
	// cout << endl;
	// s.print(s.root, 2);
	// cout << endl;
	// s.print(s.root, 3);
	// cout << endl;
	// s.print(s.root, 4);
	// cout << endl;
	// s.print(s.root, 5);
	// cout << endl;

	// cout << "-------" << endl;

	// s.access(10);

	// s.print(s.root, 1);
	// cout << endl;
	// s.print(s.root, 2);
	// cout << endl;
	// s.print(s.root, 3);
	// cout << endl;
	// s.print(s.root, 4);
	// cout << endl;
	// s.print(s.root, 5);
	// cout << endl;

	// cout << "-------" << endl;

	// s.access(2);

	// s.print(s.root, 1);
	// cout << endl;
	// s.print(s.root, 2);
	// cout << endl;
	// s.print(s.root, 3);
	// cout << endl;
	// s.print(s.root, 4);
	// cout << endl;
	// s.print(s.root, 5);
	// cout << endl;

	// cout << "-------" << endl;
}