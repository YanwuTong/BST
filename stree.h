//stree.h

#ifndef STREE_H 
#define STREE_H

#include <iostream>
#include <cstddef>

struct node{
	int value;
	node* parent;
	node* left;
	node* right;

	node(int a = 0): value(a), parent(0), left(0), right(0){ }
};


typedef struct node node;

class stree{
public:
	//return the pointer to node with i or last node if i not found
	node* accessHelper(int i);
	//left single rotate
	node* left_rotate(node* n);
	//right single rotate
	node* right_rotate(node* n);
	//left double rotate
	void double_left(node* n);
	//right double rotate
	void double_right(node* n);
	//left first and right second
	void LR_rotate(node* n);
	//right first and left second
	void RL_rotate(node* n);
	//select which rotation will use
	void select(node* n);
	//splay node with i to the root or the last node on the path
	void access(int i);
	//return pointer to the maximum number in the tree
	int findMax();
	//combine two tree together
	node* join(stree t1, stree t2);
	//split one tree to two subtree with i be the root
	void split(int i, stree& t1, stree& t2);
	//check value i 
	void find(int i);

  
	//insert node with i if there is no i in the tree, otherwise, cout error
	void insert(int i, stree& t1, stree& t2);
	//delete the node with value i or last node on the path
	void delet(int i, stree& t1, stree& t2);

	int height(node* n);




	//print the tree level by level
	void printHelper(node* root, int level);

	void print();


	node* root;
};

#endif
