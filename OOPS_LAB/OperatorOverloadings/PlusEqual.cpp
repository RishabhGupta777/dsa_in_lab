#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char str[100];

public:
    MyString() {}
    MyString(const char* s) {
        strcpy(str, s);
    }

    // Overload +
    MyString operator+(const MyString& s) {
        MyString temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    // Overload ==
    bool operator==(const MyString& s) {
        return strcmp(str, s.str) == 0;
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    MyString s1("Hello "), s2("World"), s3("Hello World");

    MyString s4 = s1 + s2;
    cout << "Concatenation: ";
    s4.display();

    if (s4 == s3)
        cout << "Strings are equal." << endl;
    else
        cout << "Strings are not equal." << endl;

    return 0;
}
