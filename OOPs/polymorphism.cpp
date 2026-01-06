#include <iostream>
using namespace std;

// C++ supports two main types of polymorphism:
//		1. Static (Compile-Time) Polymorphism
// 		2.Dynamic (Run-Time) Polymorphism

//Static polymorphism is resolved at compile time.
// The compiler decides which function or operator to call.


//1. Function / Method Overloading
//Multiple functions with the same name but different parameters in the same scope.
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
};

//2. operator Overloading
//Defining custom behavior for operators for user-defined types.
class Point {
public:
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    
    Point operator+(const Point &p) {
        return Point(x + p.x, y + p.y);
    }
};

int main() {
    Calculator c;
    cout << c.add(2, 3) << endl;      // Calls add(int, int)
    cout << c.add(2.5, 3.5) << endl;  // Calls add(double, double)

    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;   // Calls operator+ at compile time
    cout << p3.x << " " << p3.y;
}


//Dynamic polymorphism is resolved at runtime, not compile time.
//The compiler does not know which function will be called; 
// it depends on the actual object type at runtime.

// How to achieve dynamic polymorphism in C++
// Virtual functions + inheritance
// Method overriding

#include <iostream>
using namespace std;

class Employee {
public:
    virtual void work() {  // virtual = runtime polymorphism
        cout << "Employee working" << endl;
    }
};

class Developer : public Employee {
public:
    void work() override {   // override base class method
        cout << "Developer coding" << endl;
    }
};

int main() {
    Employee* e1 = new Employee();
    Employee* e2 = new Developer();

    e1->work();   // Employee working
    e2->work();   // Developer coding (decided at runtime!)
}
