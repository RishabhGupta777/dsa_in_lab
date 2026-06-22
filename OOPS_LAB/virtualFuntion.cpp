#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* ptr;   // Base class pointer

    Dog d;
    Cat c;

    // Pointing base class pointer to derived class objects
    ptr = &d;
    ptr->sound();   // Calls Dog's version of sound()

    ptr = &c;
    ptr->sound();   // Calls Cat's version of sound()

    return 0;
}
