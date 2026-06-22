#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    cout << "Enter number of productions: ";
    cin >> n;

    // Array to store productions
    string productions[100];

    cin.ignore(); // To clear input buffer

    cout << "Enter productions (e.g., S -> AB | a):\n";
    for (int i = 0; i < n; i++) {
        cout << "Production " << i + 1 << ": ";
        getline(cin, productions[i]);
    }

    // Display productions
    cout << "\n--- CFG Productions ---\n";
    for (int i = 0; i < n; i++) {
        cout << productions[i] << endl;
    }

    return 0;
}