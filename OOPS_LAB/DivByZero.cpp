#include <iostream>
using namespace std;

int main() {
    try {
        int a, b;
        cout << "Enter numerator: ";
        cin >> a;
        cout << "Enter denominator: ";
        cin >> b;

        if (b == 0) {
            throw runtime_error("Error: Division by zero is not allowed!");
        }

        cout << "Result = " << a / b << endl;
    }
    catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
