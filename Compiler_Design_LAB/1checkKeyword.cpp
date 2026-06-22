#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;

// Set of C++ keywords
set<string> keywords = {
    "int", "float", "double", "char", "if", "else", "while", "for",
    "return", "void", "class", "public", "private", "protected",
    "include", "using", "namespace", "std", "switch", "case", "break",
    "continue", "do", "struct", "enum", "const", "static", "new", "delete"
};

// Function to check keyword
bool isKeyword(string word) {
    return keywords.find(word) != keywords.end();
}

// Function to check valid variable
bool isValidVariable(string var) {
    if (!(isalpha(var[0]) || var[0] == '_'))
        return false;

    for (char c : var) {
        if (!(isalnum(c) || c == '_'))
            return false;
    }

    // Variable should not be a keyword
    if (isKeyword(var))
        return false;

    return true;
}

// Function to check comment
bool isComment(string line) {
    if (line.substr(0, 2) == "//")
        return true;
    if (line.substr(0, 2) == "/*" && line.substr(line.size() - 2) == "*/")
        return true;
    return false;
}

// Function to count words
int countWords(string str) {
    int count = 0;
    bool inWord = false;

    for (char c : str) {
        if (isspace(c)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    return count;
}

int main() {
    string input;

    // a) Check Keyword
    cout << "Enter a word to check keyword: ";
    cin >> input;
    if (isKeyword(input))
        cout << "It is a keyword\n";
    else
        cout << "Not a keyword\n";

    // b) Check Variable
    cout << "\nEnter a variable name: ";
    cin >> input;
    if (isValidVariable(input))
        cout << "Valid variable name\n";
    else
        cout << "Invalid variable name\n";

    // c) Check Comment
    cin.ignore(); // clear buffer
    cout << "\nEnter a line to check comment: ";
    getline(cin, input);
    if (isComment(input))
        cout << "It is a comment\n";
    else
        cout << "Not a comment\n";

    // d) Count words
    cout << "\nEnter a string to count words: ";
    getline(cin, input);
    cout << "Word count: " << countWords(input) << endl;

    return 0;
}