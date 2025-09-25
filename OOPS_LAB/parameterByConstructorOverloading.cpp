#include <iostream>
#include <string>
using namespace std;

class Perimeter {
public:
    float result;
    int a, b, c; 

    // Function overloading for input
    void input(int x) {
        cout << "Enter the side of square: ";
        cin >> a;
    }

    void input(int x, int y) {
        cout << "Enter length: ";
        cin >> a;
        cout << "Enter breadth: ";
        cin >> b;
    }

    void input(int x, int y, int z) {
        cout << "Enter 1st side: ";
        cin >> a;
        cout << "Enter 2nd side: ";
        cin >> b;
        cout << "Enter 3rd side: ";
        cin >> c;
    }

    // Constructor overloading
    Perimeter(int x) {
        input(x);
        result = 4 * a;
        print("square");
    }

    Perimeter(int x, int y) {
        input(x, y);
        result = 2 * (a + b);
        print("rectangle");
    }

    Perimeter(int x, int y, int z) {
        input(x, y, z);
        result = a + b + c;
        print("triangle");
    }

    void print(string s) {
        cout << "Perimeter of " << s << " = " << result << endl;
    }
};

int main() {
    Perimeter p1(0);       // square
    Perimeter p2(0, 0);    // rectangle
    Perimeter p3(0, 0, 0); // triangle
    return 0;
}
