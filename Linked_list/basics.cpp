#include <iostream>
using namespace std;


struct Node{
	int data;
	Node* next;

	Node(int data, Node* next= nullptr){
		this->data= data;
		this->next= next;
	}
};

void insertbeginning(Node* &head, int val ){

	Node* temp= new Node(val, head);
	head= temp;
}

void insertAtEnd(Node* &head, int val){

	if(head->next == NULL){
		Node* temp= new Node(val);
		head->next = temp;
		return;
	}

	insertAtEnd(head->next, val);

}

void deleteNode(Node* &head, int val) {		// when we call this it becomes head->next so it still stores head
    if (head == nullptr) return;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    deleteNode(head->next, val);
}




int main(){
	Node* third = new Node(30);
	Node* second = new Node(20,third);
	Node* first = new Node(10,second);

	// first->data = 10;
	// first->next= second;
	// second->data= 20;
	// second-> next= third;
	// third->data=30;
	// third->next = NULL;

	insertbeginning(first, 0);
	insertAtEnd(first, 40);
	insertAtEnd(third, 50);
	deleteNode(first, 20);
	// cout<<first->data <<endl;

	Node* temp = first;

	while(temp != NULL){
		cout<<temp->data<<endl;
		temp= temp->next;
	}

	cout<<first<<endl;

	return 0;

}