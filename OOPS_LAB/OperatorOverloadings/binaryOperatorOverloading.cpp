#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    // Constructor to initialize complex number
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // Overload the + operator
    Complex operator + (const Complex &obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    // Function to display complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.5, 2.5), c2(1.6, 4.2);

    cout << "First Complex number: ";
    c1.display();

    cout << "Second Complex number: ";
    c2.display();

    Complex c3 = c1 + c2;  // Using overloaded + operator

    cout << "Sum of two Complex numbers: ";
    c3.display();

    return 0;
}



// #include <iostream>
// using namespace std;

// class Number {
//     int value;

// public:
//     // Constructor
//     Number(int v = 0) {
//         value = v;
//     }

//     // Overload the + operator
//     Number operator + (const Number &obj) {
//         Number temp;
//         temp.value = value + obj.value;
//         return temp;
//     }

//     // Display function
//     void display() {
//         cout << value << endl;
//     }
// };

// int main() {
//     Number a(2), b(4);   // Two numbers

//     cout << "First number: ";
//     a.display();

//     cout << "Second number: ";
//     b.display();

//     Number c = a + b;    // Using overloaded + operator

//     cout << "Sum of two numbers: ";
//     c.display();

//     return 0;
// }
