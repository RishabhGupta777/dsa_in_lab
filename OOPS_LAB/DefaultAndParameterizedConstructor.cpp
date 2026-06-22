#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Default Constructor
    Student() {
        name = "Unknown";
        age = 0;
        cout << "Default constructor called." << endl;
    }

    // Parameterized Constructor
    Student(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized constructor called." << endl;
    }

    // Function to display student info
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Creating object using Default Constructor
    Student s1;
    s1.display();

    cout << endl;

    // Creating object using Parameterized Constructor
    Student s2("Rishabh", 20);
    s2.display();

    return 0;
}
