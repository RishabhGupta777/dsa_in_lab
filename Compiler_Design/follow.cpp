#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> prod;
map<char, set<char>> FIRST, FOLLOW;
set<char> nonTerminals;
char startSymbol;

//  FIRST ka code
set<char> findFirst(char c) {
    // If already computed
    if (!FIRST[c].empty())
        return FIRST[c];

    set<char> result;

    // If terminal
    if (!isupper(c)) {
        result.insert(c);
        return result;
    }

    // For each production of c
    for (string RHS : prod[c]) {
        // epsilon production
        if (RHS == "#") {
            result.insert('#');
            continue;
        }

        for (int i = 0; i < RHS.size(); i++) {
            set<char> temp = findFirst(RHS[i]);

            for (char t : temp)
                if (t != '#')
                    result.insert(t);

            // stop if epsilon not present
            if (temp.find('#') == temp.end())
                break;

            // if last symbol and epsilon present
            if (i == RHS.size() - 1)
                result.insert('#');
        }
    }

    FIRST[c] = result;
    return result;
}

//FOLLOW  ka code
void findFollow(char c) {

    // add $ to start symbol
    if (c == startSymbol)
        FOLLOW[c].insert('$');

    for (auto &p : prod) {
        char LHS = p.first;

        for (string RHS : p.second) {
            for (int i = 0; i < RHS.size(); i++) {

                if (RHS[i] == c) {

                    // if symbol after c exists
                    if (i + 1 < RHS.size()) {

                        set<char> nextFirst = findFirst(RHS[i+1]);

                        for (char t : nextFirst)
                            if (t != '#')
                                FOLLOW[c].insert(t);

                        // if epsilon in FIRST(next)
                        if (nextFirst.count('#')) {
                            if (LHS != c)
                                findFollow(LHS);

                            for (char t : FOLLOW[LHS])
                                FOLLOW[c].insert(t);
                        }
                    }
                    else {
                        // c at end
                        if (LHS != c) {
                            findFollow(LHS);
                            for (char t : FOLLOW[LHS])
                                FOLLOW[c].insert(t);
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

    cout << "Enter productions (use # for epsilon, e.g. R=+TR):\n";

    for (int i=0;i<n;i++) {
        string s;
        cin >> s;
        char LHS = s[0];
        string RHS = s.substr(2);
        prod[LHS].push_back(RHS);
        nonTerminals.insert(LHS);

        if (i==0)
            startSymbol = LHS;
    }

    // FIRST
    for (char nt : nonTerminals)
        findFirst(nt);

    // FOLLOW
    for (char nt : nonTerminals)
        findFollow(nt);

    // print FIRST
    cout << "\nFIRST sets:\n";
    for (auto &p : FIRST) {
        cout << "FIRST(" << p.first << ") = { ";
        for (char c : p.second)
            cout << c << " ";
        cout << "}\n";
    }

    // print FOLLOW
    cout << "\nFOLLOW sets:\n";
    for (auto &p : FOLLOW) {
        cout << "FOLLOW(" << p.first << ") = { ";
        for (char c : p.second)
            cout << c << " ";
        cout << "}\n";
    }

    return 0;
}