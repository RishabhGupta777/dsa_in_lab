#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

map<char, set<char>> leading, trailing;
map<char, vector<string>> productions;

set<char> visitedLeading, visitedTrailing;

// Function to find LEADING
void findLeading(char nonTerminal) {
    if (visitedLeading.count(nonTerminal)) return;
    visitedLeading.insert(nonTerminal);

    for (auto prod : productions[nonTerminal]) {
        if (!isupper(prod[0])) {
            leading[nonTerminal].insert(prod[0]);
        }
        else {
            findLeading(prod[0]);
            leading[nonTerminal].insert(
                leading[prod[0]].begin(),
                leading[prod[0]].end()
            );

            if (prod.length() > 1 && !isupper(prod[1])) {
                leading[nonTerminal].insert(prod[1]);
            }
        }
    }
}

// Function to find TRAILING
void findTrailing(char nonTerminal) {
    if (visitedTrailing.count(nonTerminal)) return;
    visitedTrailing.insert(nonTerminal);

    for (auto prod : productions[nonTerminal]) {
        int n = prod.length();

        if (!isupper(prod[n - 1])) {
            trailing[nonTerminal].insert(prod[n - 1]);
        }
        else {
            findTrailing(prod[n - 1]);
            trailing[nonTerminal].insert(
                trailing[prod[n - 1]].begin(),
                trailing[prod[n - 1]].end()
            );

            if (n > 1 && !isupper(prod[n - 2])) {
                trailing[nonTerminal].insert(prod[n - 2]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter productions (e.g., E->E+T):\n";
    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;

        char lhs = prod[0];
        string rhs = prod.substr(3);
        productions[lhs].push_back(rhs);
    }

    for (auto p : productions) {
        findLeading(p.first);
        findTrailing(p.first);
    }

    cout << "\nLEADING:\n";
    for (auto p : leading) {
        cout << p.first << " : { ";
        for (auto ch : p.second) cout << ch << " ";
        cout << "}\n";
    }

    cout << "\nTRAILING:\n";
    for (auto p : trailing) {
        cout << p.first << " : { ";
        for (auto ch : p.second) cout << ch << " ";
        cout << "}\n";
    }

    return 0;
}