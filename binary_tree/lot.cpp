#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void levelOrderTraversal(Node* root){

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* current = q.front();

		if(current->left != NULL){
		q.push(current->left);
		}
		if(current->right != NULL){
		q.push(current->right);
		}
		cout<<current->data<<endl;

		q.pop();
	}
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    return 0;
}
