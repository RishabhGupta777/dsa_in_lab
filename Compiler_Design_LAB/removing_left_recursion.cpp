#include <iostream>
#include <vector>
#include <string>
using namespace std;

void removeLeftRecursion(string production) {
    string lhs, rhs;
    int pos = production.find("->");

    lhs = production.substr(0, pos);
    rhs = production.substr(pos + 2);

    vector<string> alternatives;
    string temp = "";

    // Split RHS by '|'
    for (char c : rhs) {
        if (c == '|') {
            alternatives.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    alternatives.push_back(temp);  //-> "|" ke baad wake ko push karega

    vector<string> alphas; // recursive parts
    vector<string> betas;  // non-recursive parts

    //loop lagao alpha ko detect karne ke liye
    for (string alt : alternatives) {
        if (alt.substr(0, lhs.length()) == lhs) {
            alphas.push_back(alt.substr(lhs.length()));
        } else {
            betas.push_back(alt);
        }
    }

    if (alphas.empty()) {
        cout << "No left recursion detected." << endl;
        return;
    }

    string new_lhs = lhs + "'";

    cout << "Transformed Grammar:" << endl;

    // Rule 1-->gives E -> TE'
    cout << lhs << " -> ";
    for (int i = 0; i < betas.size(); i++) {
        cout << betas[i] << new_lhs;
        if (i != betas.size() - 1) cout << " | ";
    }
    cout << endl;

    // Rule 2 gives E' -> +TE' | ε
    cout << new_lhs << " -> ";
    for (int i = 0; i < alphas.size(); i++) {
        cout << alphas[i] << new_lhs << " | ";
    }
    cout << "ε" << endl;
}

int main() {
    string gram = "E->E+T|T";
    removeLeftRecursion(gram);
    return 0;
}

//input --> E -> E+T | T