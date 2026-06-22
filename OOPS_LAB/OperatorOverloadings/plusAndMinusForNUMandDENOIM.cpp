#include <iostream>
using namespace std;

class Rational {
    int num, den; // numerator and denominator

public:
    Rational(int n = 0, int d = 1) {
        num = n;
        den = d;
    }

    // Overload +
    Rational operator+(const Rational& r) {
        int n = num * r.den + r.num * den;
        int d = den * r.den;
        return Rational(n, d);
    }

    // Overload -
    Rational operator-(const Rational& r) {
        int n = num * r.den - r.num * den;
        int d = den * r.den;
        return Rational(n, d);
    }

    void display() {
        cout << num << "/" << den << endl;
    }
};

int main() {
    Rational r1(2, 3), r2(3, 4);

    cout << "Addition: ";
    (r1 + r2).display();

    cout << "Subtraction: ";
    (r1 - r2).display();

    return 0;
}
