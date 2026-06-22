#include <iostream>
#include <vector>
using namespace std;

// Function to encrypt text using Rail Fence Cipher
string encryptRailFence(string text, int key) {
    vector<vector<char>> rail(key, vector<char>(text.length(), '\n'));

    bool dir_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < text.length(); i++) {
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;

        rail[row][col++] = text[i];

        dir_down ? row++ : row--;
    }

    string result;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            if (rail[i][j] != '\n')
                result.push_back(rail[i][j]);

    return result;
}

// Function to decrypt Rail Fence Cipher
string decryptRailFence(string cipher, int key) {
    vector<vector<char>> rail(key, vector<char>(cipher.length(), '\n'));

    bool dir_down;
    int row = 0, col = 0;

    // Mark the positions
    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        rail[row][col++] = '*';

        dir_down ? row++ : row--;
    }

    // Fill the marked positions with cipher text
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];

    // Now read the matrix in zig-zag manner
    string result;
    row = 0, col = 0;

    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        if (rail[row][col] != '\n')
            result.push_back(rail[row][col++]);

        dir_down ? row++ : row--;
    }

    return result;
}

int main() {
    string text;
    int key;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter key (number of rails): ";
    cin >> key;

    string encrypted = encryptRailFence(text, key);
    cout << "Encrypted Text: " << encrypted << endl;

    string decrypted = decryptRailFence(encrypted, key);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}