#include <iostream>
#include <string>
using namespace std;

// Function to perform XOR
string XOR(string a, string b)
{
    string result = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

// Simple round function
string roundFunction(string right, string key)
{
    return XOR(right, key);
}

int main()
{
    string plaintext, key;
    cout << "Enter 8-bit plaintext (binary): ";
    cin >> plaintext;
    cout << "Enter 8-bit key (binary): ";
    cin >> key;

    string left = plaintext.substr(0, 4);
    string right = plaintext.substr(4, 4);

    cout << "\nInitial Left: " << left;
    cout << "\nInitial Right: " << right;

    // Encryption (1 round)
    string f = roundFunction(right, key.substr(0, 4));
    string newRight = XOR(left, f);
    string newLeft = right;

    string cipher = newLeft + newRight;
    cout << "\n\nCipher Text: " << cipher << endl;

    // Decryption
    string dleft = cipher.substr(0, 4);
    string dright = cipher.substr(4, 4);

    string f2 = roundFunction(dleft, key.substr(0, 4));
    string originalLeft = XOR(dright, f2);
    string originalRight = dleft;

    string decrypted = originalLeft + originalRight;
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}

