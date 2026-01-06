#include <iostream>
using namespace std;

//An interface is a class that contains only pure virtual functions
//  and no implementation, used to achieve full abstraction, no data members
// abstract class can have both concrete and pure virtual functions 

// c++ doesnt have the key word interface 


class Shape {
public:
// no function implementation , cannot create shape object,
//  forces derived class to implement functions 

//interface defines what to do
    virtual void draw() = 0;   // pure virtual function
    virtual double area() = 0;

    virtual ~Shape() {}        // important
};


class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() override {
        cout << "Drawing Circle\n"; // any class that derives from Shape must implement draw
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
    double length, breadth;
public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

	// these functions define how to do
    void draw() override {
        cout << "Drawing Rectangle\n";
    }

    double area() override {
        return length * breadth;
    }
};

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);

    s1->draw(); // interface nables runtime polymorphism
    cout << s1->area() << endl;

    s2->draw();
    cout << s2->area() << endl;

    delete s1;
    delete s2;
}
