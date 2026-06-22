#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks;
};

int main() {
    Student s1; 

    cout << "Enter name: ";
    getline(cin, s1.name);
     //getline(cin, s1.name); ka use hum isliye kar rahe taki hame input full name (with spaces) mile

    cout << "Enter roll number: ";
    cin >> s1.rollNumber;

    cout << "Enter marks: ";
    cin >> s1.marks;

    cout << "\n--- Student Information ---" << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Roll Number: " << s1.rollNumber << endl;
    cout << "Marks: " << s1.marks << endl;

    return 0;
}
