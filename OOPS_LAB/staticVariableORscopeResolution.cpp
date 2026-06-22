#include <iostream>
using namespace std;

int value = 100;

class Demo {
public:
    static int count;  
    int value;         

    Demo(int v) {
        value = v;
        count++;
    }

    void show() {
        cout << "Local (member) value: " << value << endl;
        cout << "Global value using :: operator: " << ::value << endl; // Access global variable
    }

    static void displayCount() {
        cout << "Static count: " << count << endl;
    }
};

// Definition of static member using scope resolution
int Demo::count = 0; //Static member ka difinition scope resolution ko use karte hue

int main() {
    Demo obj1(10);
    Demo obj2(20);

    obj1.show();
    obj2.show();

    // Access static member using class name and ::
    Demo::displayCount();
    cout << "Accessing static variable directly: " << Demo::count << endl;

    return 0;
}