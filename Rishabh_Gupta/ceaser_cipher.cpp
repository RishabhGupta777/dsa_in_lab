#include <iostream>
#include <string>

using namespace std;

// Function to encrypt text
string encrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            result += (ch - base + shift) % 26 + base;
        } else {
            result += ch; // keep non-alphabet characters unchanged
        }
    }
    return result;
}

// Function to decrypt text
string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift); // reverse shift
}

int main() {
    string text;
    int shift;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = encrypt(text, shift);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}