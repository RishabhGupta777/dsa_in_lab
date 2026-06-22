#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find common prefix
string commonPrefix(string a, string b) {
    string result = "";
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            result += a[i];
        else
            break;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    vector<string> productions(n);

    cout << "Enter productions (Example: A->abc|abd|aef):\n";
    for (int i = 0; i < n; i++) {
        cin >> productions[i];
    }

    cout << "\nAfter Left Factoring:\n";

    for (int i = 0; i < n; i++) {
        string prod = productions[i];

        char nonTerminal = prod[0];
        string rhs = prod.substr(3); // skip A->

        vector<string> rules;
        string temp = "";

        // Split RHS by '|'
        for (char c : rhs) {
            if (c == '|') {
                rules.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        rules.push_back(temp);

        // Find common prefix among all rules
        string prefix = rules[0];
        for (int j = 1; j < rules.size(); j++) {
            prefix = commonPrefix(prefix, rules[j]);
        }

        if (prefix == "") {
            cout << prod << endl;
            continue;
        }

        // Print factored production
        cout << nonTerminal << "->" << prefix << nonTerminal << "'\n";
        cout << nonTerminal << "'->";

        for (int j = 0; j < rules.size(); j++) {
            string remaining = rules[j].substr(prefix.size());
            if (remaining == "")
                remaining = "ε";

            cout << remaining;
            if (j != rules.size() - 1)
                cout << "|";
        }
        cout << endl;
    }

    return 0;
}