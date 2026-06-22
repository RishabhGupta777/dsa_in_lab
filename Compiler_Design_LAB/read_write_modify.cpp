#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;

    // 1. WRITE to file
    ofstream outFile("example.txt");
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }
    outFile << "Hello World!" << endl;
    outFile << "This is a C++ file handling example." << endl;
    outFile.close();

    cout << "Data written to file.\n";

    // 2. READ from file
    ifstream inFile("example.txt");
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "\nReading file content:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    // 3. MODIFY file (append new content)
    ofstream modifyFile("example.txt", ios::app);
    if (!modifyFile) {
        cout << "Error opening file for modification!" << endl;
        return 1;
    }
    modifyFile << "This line is added later (modification)." << endl;
    modifyFile.close();

    cout << "\nFile modified (new data appended).\n";

    // 4. READ again to show changes
    ifstream updatedFile("example.txt");
    cout << "\nUpdated file content:\n";
    while (getline(updatedFile, line)) {
        cout << line << endl;
    }
    updatedFile.close();

    return 0;
}