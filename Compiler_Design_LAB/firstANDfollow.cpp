#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSet, followSet;
set<char> nonTerminals;
char startSymbol;

// FIRST function
void computeFirst(char c) {
    if (!isupper(c)) {
        firstSet[c].insert(c);
        return;
    }

    for (auto prod : grammar[c]) {
        bool epsilonAll = true;

        for (char symbol : prod) {
            computeFirst(symbol);

            for (char ch : firstSet[symbol]) {
                if (ch != '#')
                    firstSet[c].insert(ch);
            }

            if (firstSet[symbol].find('#') == firstSet[symbol].end()) {
                epsilonAll = false;
                break;
            }
        }

        if (epsilonAll)
            firstSet[c].insert('#');
    }
}

// FOLLOW function (iterative fix)
void computeFollow() {
    followSet[startSymbol].insert('$');

    bool changed = true;

    while (changed) {
        changed = false;

        for (auto rule : grammar) {
            char lhs = rule.first;

            for (auto prod : rule.second) {
                for (int i = 0; i < prod.size(); i++) {
                    char B = prod[i];

                    if (isupper(B)) {
                        set<char> temp;

                        // Case 1: symbols after B
                        if (i + 1 < prod.size()) {
                            char next = prod[i + 1];

                            for (char ch : firstSet[next]) {
                                if (ch != '#')
                                    temp.insert(ch);
                            }

                            // If epsilon in FIRST(next)
                            if (firstSet[next].count('#')) {
                                temp.insert(followSet[lhs].begin(), followSet[lhs].end());
                            }
                        }
                        // Case 2: B at end
                        else {
                            temp.insert(followSet[lhs].begin(), followSet[lhs].end());
                        }

                        // Add to FOLLOW(B)
                        for (char ch : temp) {
                            if (!followSet[B].count(ch)) {
                                followSet[B].insert(ch);
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter productions:\n";

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        char lhs = input[0];
        if (i == 0) startSymbol = lhs;

        nonTerminals.insert(lhs);

        string rhs = input.substr(2);
        string temp = "";

        for (char ch : rhs) {
            if (ch == '|') {
                grammar[lhs].push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        grammar[lhs].push_back(temp);
    }

    // FIRST
    for (char nt : nonTerminals)
        computeFirst(nt);

    // FOLLOW
    computeFollow();

    // Print FIRST
    cout << "\nFIRST sets:\n";
    for (char nt : nonTerminals) {
        cout << "FIRST(" << nt << ") = { ";
        for (char ch : firstSet[nt])
            cout << ch << " ";
        cout << "}\n";
    }

    // Print FOLLOW
    cout << "\nFOLLOW sets:\n";
    for (char nt : nonTerminals) {
        cout << "FOLLOW(" << nt << ") = { ";
        for (char ch : followSet[nt])
            cout << ch << " ";
        cout << "}\n";
    }

    return 0;
}