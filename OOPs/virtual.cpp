#include <iostream>
using namespace std;

class Shape {
public:
//A virtual function is a class member function that 
// is resolved at runtime and enables dynamic binding 
// and runtime polymorphism in C++.
    virtual void draw() = 0;   // pure virtual function, forces child to implement draw function

        virtual ~Shape() {
        cout << "Shape Destructor\n";
    }

};

class Circle : public Shape {
public:
    void draw() override{
        cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override{
        cout << "Drawing Rectangle\n";
    }
};

int main() {
	//Shape s; // is invalid coz geenric shape nahi ho skta
    Circle c;
    Rectangle r;

    vector<Shape*> shapes;

    shapes.push_back(&c); 
    shapes.push_back(&r);

    // Runtime resolution happens here
    for (Shape* s : shapes) { // so s = &c and then s=&r 
        s->draw();   // Decided at runtime
    }
    // s = &c;
    // c.draw();   // Drawing Circle

    // s = &r; // tells compiler to decide at runtime which one to choose
    // s->draw();   // Drawing Rectangle

    return 0;
}
