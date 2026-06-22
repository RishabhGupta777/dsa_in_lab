#include <bits/stdc++.h>
using namespace std;

int main(){
    string str="aabbaabb";
    // string str;
    // cout << "Enter string: ";
    // cin >> str;

    int i = 0;
    int a_count = 0, b_count = 0;

    // Count a's from beginning
    while (i < str.length() and str[i] == 'a') {
        a_count++;
        i++;
    }

    // Count b's after a's
    while (i < str.length() and str[i] == 'b') {
        b_count++;
        i++;
    }

    // Check CFG condition                           //suruat me hi b aa gya to
    if (i == str.length() and a_count == b_count and a_count > 0) {
        cout << "Valid string (Accepted by CFG)";
    } else {
        cout << "Invalid string (Rejected by CFG)";
    }

    return 0;
}
