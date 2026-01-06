

# Access Modifiers / Access Specifiers in C++

## What are Access Modifiers?

> **Access modifiers (also called access specifiers)** define **who can access class members (data and functions)**.

They are used to achieve **encapsulation and data hiding**.

---

## Types of Access Specifiers in C++

C++ provides **three** access specifiers:

1. `public`
2. `protected`
3. `private`

---

## 1️⃣ `public`

### Meaning

Members declared as `public`:

* Are accessible **from anywhere**
* Inside the class
* Outside the class
* In derived (child) classes

### Example

```cpp
class Student {
public:
    int rollNo;

    void display() {
        cout << rollNo << endl;
    }
};

int main() {
    Student s;
    s.rollNo = 10;   // allowed
    s.display();    // allowed
}
```

### Use case

* Interfaces
* APIs
* Methods meant for external use

---

## 2️⃣ `private` (Default in `class`)

### Meaning

Members declared as `private`:

* Are accessible **only inside the same class**
* ❌ Not accessible in derived classes
* ❌ Not accessible outside the class

### Example

```cpp
class Student {
private:
    int marks;

public:
    void setMarks(int m) {
        marks = m;
    }
};
```

```cpp
int main() {
    Student s;
    // s.marks = 90; ❌ ERROR
}
```

### Key Point

🔹 `private` is the **default access specifier** for `class`.

---

## 3️⃣ `protected`

### Meaning

Members declared as `protected`:

* Accessible **inside the class**
* Accessible **in derived classes**
* ❌ Not accessible outside the class

### Example

```cpp
class Person {
protected:
    string name;
};

class Employee : public Person {
public:
    void setName(string n) {
        name = n;   // allowed
    }
};
```

```cpp
int main() {
    Employee e;
    // e.name = "Yuvi"; ❌ ERROR
}
```

### Use case

* When derived classes need access
* Common in base classes

---

## Summary Table

| Specifier   | Same Class | Derived Class | Outside Class |
| ----------- | ---------- | ------------- | ------------- |
| `public`    | ✅          | ✅             | ✅             |
| `protected` | ✅          | ✅             | ❌             |
| `private`   | ✅          | ❌             | ❌             |

---

## Default Access Specifiers

| Keyword Used | Default Access |
| ------------ | -------------- |
| `class`      | `private`      |
| `struct`     | `public`       |

### Example

```cpp
struct A {
    int x;  // public by default
};

class B {
    int y;  // private by default
};
```

---

## Access Specifiers in Inheritance

Access specifiers also affect **how base class members are inherited**.

### Syntax

```cpp
class Derived : access_specifier Base { };
```

---

### Inheritance Access Rules

| Base Member | Public Inheritance | Protected Inheritance | Private Inheritance |
| ----------- | ------------------ | --------------------- | ------------------- |
| `public`    | public             | protected             | private             |
| `protected` | protected          | protected             | private             |
| `private`   | ❌ not accessible   | ❌                     | ❌                   |

🔴 **Private members are never directly accessible in derived classes**.

---

### Example

```cpp
class Base {
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Derived : public Base {
    void func() {
        a = 10; // OK
        b = 20; // OK
        // c = 30; ❌
    }
};
```

---

## Why Access Specifiers Are Important

### 1️⃣ Encapsulation

* Hide internal data
* Prevent accidental modification

### 2️⃣ Security

* Protect sensitive data

### 3️⃣ Maintainability

* Change internal implementation without affecting users

---

## Common Interview Mistakes ⚠️

❌ Thinking `protected` is accessible in `main()`
❌ Thinking `private` members are inherited
❌ Forgetting default access in `class` vs `struct`

---

## One-liner for interviews 

> **Access specifiers control the visibility of class members and help achieve encapsulation and data hiding in C++.**

---
