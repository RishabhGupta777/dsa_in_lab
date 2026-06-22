#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if a symbol is non-terminal (uppercase letter)
bool isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    vector<string> productions;
    cout << "Enter productions (e.g., E->E+T):\n";

    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;
        productions.push_back(prod);
    }

    bool isOperatorGrammar = true;

    for (auto prod : productions) {
        // Find RHS (after ->)
        int pos = prod.find("->");
        string rhs = prod.substr(pos + 2);

        // Condition 1: No epsilon
        if (rhs == "ε" || rhs == "e") {
            isOperatorGrammar = false;
            break;
        }

        // Condition 2: No adjacent non-terminals
        for (int i = 0; i < rhs.length() - 1; i++) {
            if (isNonTerminal(rhs[i]) && isNonTerminal(rhs[i + 1])) {
                isOperatorGrammar = false;
                break;
            }
        }

        if (!isOperatorGrammar)
            break;
    }

    if (isOperatorGrammar)
        cout << "\nThe grammar is an Operator Precedence Grammar.\n";
    else
        cout << "\nThe grammar is NOT an Operator Precedence Grammar.\n";

    return 0;
}