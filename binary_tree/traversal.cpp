#include <iostream>
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

// Inorder  (Left → node → Right)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder  (node → Left → Right)
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder  (Left → Right → node)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

	//4 2 5 1 6 3 7
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

	// 1 2 4 5 3 6 7
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

	// 4 5 2 6 7 3 1
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
