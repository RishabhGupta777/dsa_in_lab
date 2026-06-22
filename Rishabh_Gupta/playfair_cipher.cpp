#include <bits/stdc++.h>

using namespace std;

class PlayfairCipher {
    char matrix[5][5];
    map<char, pair<int,int>> pos;

public:
    void generateMatrix(string key) {
        set<char> used;
        string result = "";

        // Convert key to uppercase and remove duplicates
        for(char &c : key) {
            if(c == 'j') c = 'i';
            if(!used.count(c) && isalpha(c)) {
                used.insert(c);
                result += c;
            }
        }

        // Add remaining alphabets
        for(char c = 'a'; c <= 'z'; c++) {
            if(c == 'j') continue;
            if(!used.count(c)) {
                used.insert(c);
                result += c;
            }
        }

        // Fill matrix
        int k = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                matrix[i][j] = result[k];
                pos[result[k]] = {i, j};
                k++;
            }
        }
    }

    string prepareText(string text) {
        string res = "";

        for(char &c : text) {
            if(c == 'j') c = 'i';
            if(isalpha(c)) res += c;
        }

        for(int i = 0; i < res.length(); i += 2) {
            if(i+1 == res.length() || res[i] == res[i+1]) {
                res.insert(i+1, "x");
            }
        }

        if(res.length() % 2 != 0) res += 'x';

        return res;
    }

    string encrypt(string text) {
        string res = "";
        for(int i = 0; i < text.length(); i += 2) {
            char a = text[i], b = text[i+1];
            auto p1 = pos[a], p2 = pos[b];

            // Same row
            if(p1.first == p2.first) {
                res += matrix[p1.first][(p1.second + 1) % 5];
                res += matrix[p2.first][(p2.second + 1) % 5];
            }
            // Same column
            else if(p1.second == p2.second) {
                res += matrix[(p1.first + 1) % 5][p1.second];
                res += matrix[(p2.first + 1) % 5][p2.second];
            }
            // Rectangle
            else {
                res += matrix[p1.first][p2.second];
                res += matrix[p2.first][p1.second];
            }
        }
        return res;
    }

    string decrypt(string text) {
        string res = "";
        for(int i = 0; i < text.length(); i += 2) {
            char a = text[i], b = text[i+1];
            auto p1 = pos[a], p2 = pos[b];

            // Same row
            if(p1.first == p2.first) {
                res += matrix[p1.first][(p1.second + 4) % 5];
                res += matrix[p2.first][(p2.second + 4) % 5];
            }
            // Same column
            else if(p1.second == p2.second) {
                res += matrix[(p1.first + 4) % 5][p1.second];
                res += matrix[(p2.first + 4) % 5][p2.second];
            }
            // Rectangle
            else {
                res += matrix[p1.first][p2.second];
                res += matrix[p2.first][p1.second];
            }
        }
        return res;
    }

    void displayMatrix() {
        cout << "Matrix:\n";
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    PlayfairCipher pf;
    string key, text;

    cout << "Enter key: ";
    cin >> key;

    cout << "Enter plaintext: ";
    cin >> text;

    pf.generateMatrix(key);
    pf.displayMatrix();

    string prepared = pf.prepareText(text);
    string encrypted = pf.encrypt(prepared);
    string decrypted = pf.decrypt(encrypted);

    cout << "\nPrepared Text: " << prepared;
    cout << "\nEncrypted Text: " << encrypted;
    cout << "\nDecrypted Text: " << decrypted;

    return 0;
}