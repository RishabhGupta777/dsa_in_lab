#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter production (A->Aa/b): ";
    cin >> input;

    char A = input[0];
    string rhs = input.substr(3);

    string alpha[10], beta[10];
    int a = 0, b = 0;

    for(int i = 0; i < rhs.length(); i++) {
        string temp = "";

        while(i < rhs.length() && rhs[i] != '/') {
            temp += rhs[i];
            i++;
        }

        if(temp[0] == A)
            alpha[a++] = temp.substr(1);
        else
            beta[b++] = temp;
    }

    if(a == 0) {
        cout << "No Left Recursion";
    } else {
        cout << "Left Recursion Found\n";
        cout << "After Removal:\n";

        cout << A << " -> ";
        for(int i = 0; i < b; i++) {
            cout << beta[i] << A << "' ";
            if(i != b-1) cout << "| ";
        }

        cout << "\n" << A << "' -> ";
        for(int i = 0; i < a; i++) {
            cout << alpha[i] << A << "' ";
            if(i != a-1) cout << "| ";
        }
        cout << "| e";
    }

    return 0;
}