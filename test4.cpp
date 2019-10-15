//test4.cpp
//test the insert function
#include "stree.h"
#include <iostream>

using namespace std;

int main(){

	stree s;



	stree t1, t2;
	t1.root = NULL;
	t2.root = NULL;


	s.insert(1, t1, t2);

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

	s.insert(100, t1, t2);

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


	s.insert(2, t1, t2);

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


	s.insert(99, t1, t2);

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


	s.insert(51, t1, t2);

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


	s.insert(50, t1, t2);

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


	s.insert(101, t1, t2);

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

	s.find(1);

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
	s.print(s.root, 6);
	cout << endl;











}