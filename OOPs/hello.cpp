#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;

public:

	void show(){
		cout<<"this: "<<this<<endl;
	}
    // 1️⃣ Default constructor
    BankAccount() {
        accountNumber = 0;
        holderName = "NA";
        balance = 0.0;
        cout << "Default constructor called\n";
    }

    // 2️⃣ Constructor with account number only
    BankAccount(int accountNumber) {
        this->accountNumber = accountNumber;
        holderName = "NA";
        balance = 0.0;
        cout << "Constructor with account number called\n";
    }

    // 3️⃣ Constructor with account number + name
    BankAccount(int accountNumber, string name) {
        this->accountNumber = accountNumber;
        holderName = name;
        balance = 0.0;
        cout << "Constructor with account number & name called\n";
    }

    // 4️⃣ Constructor with all details
    BankAccount(int accountNumber, string name, double bal) {
        this->accountNumber = accountNumber;
        holderName = name;
        balance = bal;
        cout << "Constructor with all details called\n";
    }

    void display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nHolder Name  : " << holderName;
        cout << "\nBalance      : " << balance << endl;
    }
};

int main() {
    BankAccount a1;                       // default
    BankAccount a2(101);                  // acc number
    BankAccount a3(102, "Yuvi");           // acc + name
    BankAccount a4(103, "Yuvi", 5000.50);  // full details

	a1.show();
    a1.display();
    a2.display();
    a3.display();
    a4.display();

    return 0;
}
