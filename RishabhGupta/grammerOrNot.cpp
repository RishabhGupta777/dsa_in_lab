#include <iostream>
using namespace std;

bool checkString(string str) {
    int n = str.length();
    
    // Must be even length
    if (n % 2 != 0) return false;

    int i = 0;

    // Count 'a's
    while (i < n && str[i] == 'a') {
        i++;
    }

    int countA = i;

    // Count 'b's
    while (i < n && str[i] == 'b') {
        i++;
    }

    int countB = i - countA;

    // Check conditions
    if (i == n && countA == countB && countA > 0)
        return true;

    return false;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    if (checkString(str))
        cout << "String belongs to grammar\n";
    else
        cout << "String does NOT belong to grammar\n";

    return 0;
}