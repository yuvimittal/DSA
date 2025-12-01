#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x; // coz addresss is a type int* $$
    int ** q = &p;


    cout << "x = " << x << endl;
    cout << "Address of x = " << &x << endl;  
    cout << " value of p is address of x= " << p << endl;  
    cout << "*p, the value stored in x = " << *p << endl;      // pointing at. the addres value stored in p
    cout << "value of q  = " << q << endl;  
    cout << "Address of q = " << &q << endl;  
    cout << "pointer in q = " << *q << endl;  
    cout << "double pointer of q  = " << **q << endl;  

    *p = 20; // changes value of 
    cout << "x after change = " << x << endl;
}
