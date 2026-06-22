#include <iostream>
#include <string>
using namespace std;

// Define a structure for Student
struct Student {
    string name;
    int rollNumber;
    float marks;
};

int main() {
    Student s1; // Declare a structure variable

    // Input student details
    cout << "Enter name: ";
    getline(cin, s1.name);

    cout << "Enter roll number: ";
    cin >> s1.rollNumber;

    cout << "Enter marks: ";
    cin >> s1.marks;

    // Display student details
    cout << "\n--- Student Information ---" << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Roll Number: " << s1.rollNumber << endl;
    cout << "Marks: " << s1.marks << endl;

    return 0;
}
