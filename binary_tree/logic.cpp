#include<iostream>
using namespace std;



class node {
	public:
	int data;
	node* left;
	node* right;

	node(int d){
		this -> data = d;
		this-> left = NULL;
		this -> right = NULL;

	}
};

node* build(node* root){

	cout << "enter data:" <<endl;
	int data;
	cin>> data;
	root = new node(data);

	if(data == -1){
		return NULL;
	}

	cout<< "in left of data :"<< data<<endl;
	build(root->left);
	cout<< "in right of data :"<< data<<endl;
	build(root->right);

	return root;

}


int main(){

	node* root = NULL;
	build(root);

}