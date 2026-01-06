
---

# **1️⃣ What is Abstraction in OOP?**

> **Abstraction** is the concept of **hiding unnecessary details** and showing **only essential features** of an object.

---


## **2️⃣ How is Abstraction implemented in C++?**

1. **Abstract Classes**

   ```cpp
   class Employee {
   public:
       virtual double calculateSalary() = 0;  // pure virtual
   };
   ```

   * Only defines **what the function should do**
   * Derived classes implement **how it’s done**

2. **Interfaces (pure abstract classes)**

   * Classes with **only pure virtual functions** can serve as interfaces

3. **Access Specifiers (Encapsulation also helps abstraction)**

   * Hide private data, expose only necessary methods

---

## **3️⃣ Example in C++**

```cpp
#include <iostream>
using namespace std;

class Shape {           // Abstract class
public:
    virtual void draw() = 0;  // WHAT to draw (abstract)
};

class Circle : public Shape {
public:
    void draw() override {     // HOW to draw
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Shape* s = new Circle();  
    s->draw();  // Only care about WHAT, not HOW
}
```

✅ Here:

* **Shape** → abstraction (you don’t know the exact shape)
* **Circle** → concrete implementation

---

# **4️⃣ Abstraction vs Encapsulation**

These two are often confused, but they are **different concepts**:

| Feature | Abstraction                                               | Encapsulation                                     |
| ------- | --------------------------------------------------------- | ------------------------------------------------- |
| Purpose | Hide implementation details, show only essential behavior | Hide data and control access                      |
| How     | Abstract class, interface                                 | Access specifiers (private/protected)             |
| Focus   | What the object does                                      | How the data is protected / accessed              |
| Example | `calculateSalary()` in `Employee`                         | `private int salary;` with `getSalary()` function |

**Mnemonic:**

* **Abstraction** = “**What** should I do?”
* **Encapsulation** = “**How** do I protect it?”

---

## **5️⃣ Why Abstraction is Important**

1. Reduces complexity
2. Enhances code reusability
3. Helps focus on **essential behavior**
4. Makes code **flexible** (e.g., runtime polymorphism)

---

## **6️⃣ Quick Comparison Table**

| Concept       | Implemented by                        | Hides                  | Shows                     | Example                          |
| ------------- | ------------------------------------- | ---------------------- | ------------------------- | -------------------------------- |
| Abstraction   | Abstract class / interface            | Implementation details | Essential behavior        | `calculateSalary()`              |
| Encapsulation | Access specifiers (private/protected) | Data                   | Controlled access methods | `private salary` + `getSalary()` |

---

### **Interview-ready one-liner**

> **Abstraction is the process of hiding internal details and exposing only relevant behavior, whereas encapsulation is about restricting access to data.**

---


