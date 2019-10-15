//prog2.cpp

#include "stree.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(){

	stree s;
	s.root = NULL;
	stree t1, t2;
	t1.root = NULL;
	t2.root = NULL;

	string input;

	cin >> input;

	while(cin >> input){
		if(input == "insert"){
			cin >> input;
			s.insert(stoi(input), t1, t2);
		}
		else if(input == "delete"){
			cin >> input;
			s.delet(stoi(input), t1, t2);
		}
		else if(input == "find"){
			cin >> input;
			s.find(stoi(input));
		}
		else if(input == "print"){
			s.print();
		}
	}




	return 0;
}
