#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Display from Base class" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {   // overrides base class function
        cout << "Display from Derived class" << endl;
    }
};

int main() {
    Base b;
    Base* basePtr;
    Derived d;

    b.display();
    d.display();

     basePtr = &b;
    basePtr->display();   // Output: Display from Base class

    basePtr = &d;
    basePtr->display();   // Calls Derived's display() due to overriding (runtime polymorphism)
    
    return 0;
}



