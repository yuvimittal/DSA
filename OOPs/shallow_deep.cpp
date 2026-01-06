#include <iostream>
using namespace std;

class Shallow {
public:
	int data;

	Shallow(int data){ // int is primitive type, copying int means copying value
		this->data = data;
	}

    // Compiler-generated copy constructor (shallow copy)
};

class Deep{
    public:

    int *data;

    Deep(int value){
        data = new int(value);
    }

    /*

    this is the real deep copy, without it both d1 and d2 points to same memory 
    now after this, there will be 2 memory in heap and change in 1 wont affect change in other
    Deep(const Deep& other) {
    data = new int(*other.data);
    }

    */
};

int main() {
    Shallow s1(10);
    Shallow s2 = s1;   // shallow copy, C++ calls copy contructer 
    Deep d1(10);
    Deep d2 = d1; // both address copy the same heap memory

	s2.data = 20;
    *d2.data = 20; //pointer coz d2.data stores the address of the value

    cout <<*d1.data << endl;  // 20
    cout<<*d2.data<<endl;       // 20 and d2.data has addres same as d1.data
	cout<< s1.data<<endl; // will print 10 coz shallow copy , both diff memory
	cout<< s2.data<<endl;


}
