#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }
    return result;
}

int main() {
    long long p, g; // public values
    long long a, b; // private keys

    cout << "Enter prime number (p): ";
    cin >> p;

    cout << "Enter primitive root (g): ";
    cin >> g;

    // Private keys
    cout << "Enter private key of User A: ";
    cin >> a;

    cout << "Enter private key of User B: ";
    cin >> b;

    // Public keys
    long long A = power(g, a, p);
    long long B = power(g, b, p);

    cout << "\nPublic key of A: " << A;
    cout << "\nPublic key of B: " << B;

    // Shared secret keys
    long long keyA = power(B, a, p);
    long long keyB = power(A, b, p);

    cout << "\n\nSecret key computed by A: " << keyA;
    cout << "\nSecret key computed by B: " << keyB;

    if (keyA == keyB)
        cout << "\n\nKey Exchange Successful!";
    else
        cout << "\n\nKey Exchange Failed!";

    return 0;
}