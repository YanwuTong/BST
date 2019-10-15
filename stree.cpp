//stree.cpp

#include "stree.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



using namespace std;

//return the pointer to node with i or last node if i not found
node* stree::accessHelper(int i){
	if(root == NULL){
		return NULL;
	}
	if(root->value == i){
		return root;
	}

	node* temp = root;
	node* prev;
	node* rotate;

	while(temp != NULL){
		if(temp->value == i){
			break;
		}
		else if(temp->value < i){
			prev = temp;
			temp = temp->right;
		}
		else{
			prev = temp;
			temp = temp->left;
		}
	}

	if(temp != NULL){
		rotate = temp;
	}
	else{
		rotate = prev;
	}

	return rotate;
}


//rotate to left, node bigger than parent
node* stree::left_rotate(node* n){
	if (n == NULL){
		return NULL;
	}
	node* par = n->parent;
	node* gra = par->parent;
	par->right = n->left;
	if(n->left){
		n->left->parent = par;
	}
	n->left = par;
	par->parent = n;
	n->parent = gra;
	if(gra){
		if(gra->left == par){
			gra->left = n;
		}
		else{
			gra->right = n;
		}
	}
	else{
		root = n;
	}
	return n;
}


//rotate to right, node smaller than parent
node* stree::right_rotate(node* n){
	if (n == NULL){
		return NULL;
	}
	node* par = n->parent;
	node* gra = par->parent;
	par->left = n->right;
	if(n->right){
		n->right->parent = par;
	}
	n->right = par;
	par->parent = n;
	n->parent = gra;
	if(gra){
		if(gra->left == par){
			gra->left = n;
		}
		else{
			gra->right = n;
		}
	}
	else{
		root = n;
	}
	return n;
}

void stree::double_left(node* n){
	left_rotate(n->parent);
	left_rotate(n);
	return;
}

void stree::double_right(node* n){
	right_rotate(n->parent);
	right_rotate(n);
	return;
}

void stree::LR_rotate(node* n){
	left_rotate(n);
	right_rotate(n);
	return;
}

void stree::RL_rotate(node* n){
	right_rotate(n);
	left_rotate(n);
	return;
}

void stree::select(node* n){
	node* par;
	node* gra;
	int i, j;
	par = n->parent;
	gra = par->parent;
	i = gra->left == par ? -1:1;
	j = par->left == n ? -1:1;
	if(i == -1 && j == -1){
		double_right(n);
	}
	else if(i == -1 && j == 1){
		LR_rotate(n);
	}
	else if(i == 1 && j == -1){
		RL_rotate(n);
	}
	else{
		double_left(n);
	}
}
void stree::access(int i){
	node* temp = accessHelper(i);
	while(root->left != temp && root->right != temp && root != temp){
		select(temp);
	}
	if(root->left == temp){
		root = right_rotate(temp);
	}
	else if(root->right == temp){
		root = left_rotate(temp);
	}
	return;
}


int stree::findMax(){
	if(root == NULL){
		return 0;
	}
	if(!root->right){
		return root->value;
	}
	node* temp = root;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp->value;
}

node* stree::join(stree t1, stree t2){
	if(t1.root == NULL){
		return t2.root;
	}
	if(t2.root == NULL){
		return t1.root;
	}
	int max = t1.findMax();
	t1.access(max);
	t1.root->right = t2.root;
	t2.root->parent = t1.root;
	stree temp;
	temp.root = t1.root;
	return temp.root;
}

void stree::split(int i, stree& t1, stree& t2){

	int curr = root->value;
	//cout << "curr = " << curr << endl;
	if(curr > i){
		//cout << "curr bigger than i" << endl;

		//cout << "root->left = " << root->left << endl;

		t1.root = root->left;
		//cout << "t1.root = " << t1.root << endl;
		if(t1.root != NULL){
			t1.root->parent = NULL;
		}
		//cout << "t2.root = " << t2.root << endl;
		t2.root = root;
		if(t2.root != NULL){
			t2.root->left = NULL;
		}
		return;
	}
	else{
		//cout << "curr euqal or smaller than i" << endl;

		t2.root = root->right;
		//cout << "t2.root = " << t2.root << endl;
		if(t2.root != NULL){
			t2.root->parent = NULL;
		}
		t1.root = root;
		if(t1.root != NULL){
			t1.root->right = NULL;
		}
		return;
	}
}

void stree::find(int i){
  if(root == NULL){
    	cout << "item " << i << " not found" << endl;
	return;
  }
	access(i);
	if(root->value == i){
		cout<< "item " << i << " found" << endl;
		return;
	}
	else{
		cout << "item " << i << " not found" << endl;
		return;
	}
}


void stree::insert(int i, stree& t1, stree& t2){
	if(root == NULL){
		//cout <<"root is NULL" << endl;
		root = new node(i);
		cout << "item " << i <<" inserted" << endl;
		return;
	}
	access(i);
	if(root->value == i){
		cout << "item " << i << " not inserted; already present" << endl;
		return;
	}
	else{
		cout << "item " << i << " inserted" << endl;
		split(i, t1, t2);
		node* temp = new node(i);
		temp->left = t1.root;
		temp->right = t2.root;
		root = temp;
		if(root->right != NULL){
			root->right->parent = root;
		}
		if(root->left != NULL){
			root->left->parent = root;
		}
		return;
	}
}

void stree::delet(int i, stree& t1, stree& t2){
	if(root == NULL){
		cout << "item " << i << " not deleted; not present" << endl;
		return;
	}
	access(i);
	if(root->value != i){
		cout << "item " << i << " not deleted; not present" << endl;
		return;
	}
	t1.root = root->left;
	t2.root = root->right;
	if(t1.root != NULL){
		t1.root->parent = NULL;
	}
	if(t2.root != NULL){
		t2.root->parent = NULL;
	}
	root = join(t1, t2);
	cout << "item " << i << " deleted" << endl;
	return;
}

int stree::height(node* n){
	if(n == NULL){
		return 0;
	}

	else{
		int lHeight = height(n->left);
		int rHeight = height(n->right);

		if(lHeight > rHeight){
			return (lHeight + 1);
		}
		else return(rHeight + 1);
	}
}

void stree::printHelper(node* root, int level){
	if(root == NULL){
		return;
	}
	if(level == 1){
		printf("%d ", root->value);
	}
	else if(level > 1){
		printHelper(root->left, level-1);
		printHelper(root->right, level-1);
	}
	return;
}

void stree::print(){
	int h = height(root);
	for(int i = 1; i <= h; i++){
		printHelper(root, i);
		printf("\n");
	}
	return;
}
