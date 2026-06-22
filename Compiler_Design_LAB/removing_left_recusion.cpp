#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void removeLeftFactoring(string production) {
    // Expected format: A->ab1|ab2|c
    size_t pos = production.find("->");
    string lhs = production.substr(0, pos);
    string rhs = production.substr(pos + 2);

    vector<string> alts;
    stringstream ss(rhs);
    string segment;
    while (getline(ss, segment, '|')) {
        alts.push_back(segment);
    }

    // Find the common prefix between the first two alternatives (simplified)
    // In a full compiler, you'd check all pairs.
    string prefix = "";
    if (alts.size() > 1) {
        string s1 = alts[0];
        string s2 = alts[1];
        for (size_t i = 0; i < min(s1.length(), s2.length()); i++) {
            if (s1[i] == s2[i]) prefix += s1[i];
            else break;
        }
    }

    if (prefix.empty()) {
        cout << "No common prefix found to factor." << endl;
        return;
    }

    string new_lhs = lhs + "'";
    
    // Output Transformed Grammar
    cout << "\nTransformed Grammar:" << endl;
    
    // Rule 1: A -> prefix A' | other_alts
    cout << lhs << " -> " << prefix << new_lhs;
    for (size_t i = 2; i < alts.size(); i++) {
        cout << " | " << alts[i];
    }
    cout << endl;

    // Rule 2: A' -> suffix1 | suffix2
    cout << new_lhs << " -> ";
    for (size_t i = 0; i < 2; i++) {
        string suffix = alts[i].substr(prefix.length());
        cout << (suffix.empty() ? "^" : suffix) << (i == 1 ? "" : " | ");
    }
    cout << endl;
}

int main() {
    string input;
    
    cout << "Enter production (e.g., A->ab1|ab2): ";
    cin >> input;

    removeLeftFactoring(input);
    return 0;
}

//input = A->aB|aC