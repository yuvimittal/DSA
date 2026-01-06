#include <iostream>
using namespace std;

//An abstract class in C++ is a class that cannot be instantiated
//  and is meant to be inherited.
//It may contain both abstract behavior (pure virtual functions)
//  and concrete behavior (implemented functions).

//A class becomes abstract if it has at least one pure virtual function. ==0

// Runtime polymorphism means the function call is resolved at
//  runtime based on the actual object type, not the pointer type.


//Abstract class is used when :
	// 1. classes share common state
	// 2. you want default behavior
	// 3. you want to enforce some behaviour but not all


// Interface is used when :
	// 1. You want to define what a class can do
	// 2. you dont wan tto share any implementation
	// 3. you want multiple inheritence

//In C++, an interface is an abstract class with only pure virtual functions 
// and no implementation, while an abstract class can provide both abstract 
// and concrete behavior.

class Employee {
protected:
    int id;
    string name;

public:
	
	Employee(int id, string name) {
    	this->id = id;
    	this->name = name;
	}

    virtual double calculateSalary() = 0;  //Any employee must know how to calculate
	//  salary, but each type calculates it differently.

    virtual void showDetails() {
        cout << "Base:" << id << " " << name << endl;
    }

    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double salary;
public:
    FullTimeEmployee(int id, string name, double salary)
        : Employee(id, name), salary(salary) {}

    double calculateSalary() override { //“This function MUST override a virtual function from base class”
        return salary;
    }

	// void showDetails() {
	// 	        cout << "Derived:" << id << " " << name << endl;

	// }
};



int main(){
	// Employee s; cant happen, coz s is just a blueprint not real object

Employee* e = new FullTimeEmployee(1, "Yuvi", 50000); // employeee belongs to fulltime is decided at runtime 

e->showDetails();          // Base class implementation
cout << e->calculateSalary();  // Derived class implementation

}