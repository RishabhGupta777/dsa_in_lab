#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to hide message in image
void encode(string inputImage, string outputImage, string message) {
    ifstream in(inputImage, ios::binary);
    ofstream out(outputImage, ios::binary);

    if (!in || !out) {
        cout << "Error opening file!" << endl;
        return;
    }

    char ch;
    
    // Copy first 54 bytes (BMP header unchanged)
    for (int i = 0; i < 54; i++) {
        in.get(ch);
        out.put(ch);
    }

    message += '#'; // End marker

    int msgIndex = 0;
    char msgChar;

    while (in.get(ch)) {
        if (msgIndex < message.size()) {
            msgChar = message[msgIndex];

            for (int i = 7; i >= 0; i--) {
                if (!in.get(ch)) break;

                char bit = (msgChar >> i) & 1;
                ch = (ch & 0xFE) | bit; // Replace LSB

                out.put(ch);
            }
            msgIndex++;
        } else {
            out.put(ch);
        }
    }

    in.close();
    out.close();
    cout << "Message encoded successfully!" << endl;
}

// Function to extract message
void decode(string image) {
    ifstream in(image, ios::binary);

    if (!in) {
        cout << "Error opening file!" << endl;
        return;
    }

    char ch;
    
    // Skip BMP header
    for (int i = 0; i < 54; i++) {
        in.get(ch);
    }

    string message = "";
    char msgChar = 0;
    int bitCount = 0;

    while (in.get(ch)) {
        msgChar = (msgChar << 1) | (ch & 1);
        bitCount++;

        if (bitCount == 8) {
            if (msgChar == '#') break;
            message += msgChar;
            msgChar = 0;
            bitCount = 0;
        }
    }

    in.close();
    cout << "Decoded Message: " << message << endl;
}

// Main function
int main() {
    int choice;
    cout << "1. Encode Message\n2. Decode Message\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        string inputImage, outputImage, message;
        cout << "Enter input BMP image: ";
        cin >> inputImage;
        cout << "Enter output image: ";
        cin >> outputImage;
        cin.ignore();
        cout << "Enter secret message: ";
        getline(cin, message);

        encode(inputImage, outputImage, message);
    } 
    else if (choice == 2) {
        string image;
        cout << "Enter encoded image: ";
        cin >> image;

        decode(image);
    } 
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}





