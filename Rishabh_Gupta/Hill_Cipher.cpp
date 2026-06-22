#include <iostream>
#include <vector>
using namespace std;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to get determinant of 2x2 matrix
int determinant(vector<vector<int>> key) {
    return (key[0][0]*key[1][1] - key[0][1]*key[1][0] + 26) % 26;
}

// Function to find inverse of key matrix
vector<vector<int>> inverseKey(vector<vector<int>> key) {
    vector<vector<int>> inv(2, vector<int>(2));

    int det = determinant(key);
    int invDet = modInverse(det, 26);

    if (invDet == -1) {
        cout << "Inverse doesn't exist!\n";
        exit(0);
    }

    inv[0][0] = key[1][1];
    inv[1][1] = key[0][0];
    inv[0][1] = -key[0][1];
    inv[1][0] = -key[1][0];

    // Apply modulo and multiply with inverse determinant
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            inv[i][j] = (inv[i][j] * invDet) % 26;
            if (inv[i][j] < 0)
                inv[i][j] += 26;
        }
    }

    return inv;
}

// Encrypt function
string encrypt(string text, vector<vector<int>> key) {
    string result = "";

    for(int i = 0; i < text.length(); i += 2) {
        int a = text[i] - 'A';
        int b = text[i+1] - 'A';

        int c1 = (key[0][0]*a + key[0][1]*b) % 26;
        int c2 = (key[1][0]*a + key[1][1]*b) % 26;

        result += char(c1 + 'A');
        result += char(c2 + 'A');
    }

    return result;
}

// Decrypt function
string decrypt(string text, vector<vector<int>> key) {
    vector<vector<int>> invKey = inverseKey(key);
    return encrypt(text, invKey); // same logic
}

int main() {
    vector<vector<int>> key(2, vector<int>(2));

    cout << "Enter 2x2 key matrix:\n";
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            cin >> key[i][j];

    string text;
    cout << "Enter plaintext (uppercase, even length): ";
    cin >> text;

    string cipher = encrypt(text, key);
    cout << "Encrypted Text: " << cipher << endl;

    string decrypted = decrypt(cipher, key);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}