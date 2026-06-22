#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // Overload +
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload -
    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overload *
    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Overload /
    Complex operator/(const Complex& c) {
        float denom = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denom,
                       (imag * c.real - real * c.imag) / denom);
    }

    // Overload +=
    Complex& operator+=(const Complex& c) {
        real += c.real;
        imag += c.imag;
        return *this;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 2), c2(1, 7);

    cout << "Addition: ";
    (c1 + c2).display();

    cout << "Subtraction: ";
    (c1 - c2).display();

    cout << "Multiplication: ";
    (c1 * c2).display();

    cout << "Division: ";
    (c1 / c2).display();

    c1 += c2;
    cout << "After += : ";
    c1.display();

    return 0;
}
