#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to find modular inverse using brute force
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}

// Function for modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }
    return result;
}

int main() {
    int p, q;

    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e;
    cout << "Enter public key e (1 < e < phi and gcd(e, phi) = 1): ";
    cin >> e;

    if (gcd(e, phi) != 1) {
        cout << "Invalid e. gcd(e, phi) must be 1.\n";
        return 0;
    }

    int d = modInverse(e, phi);

    cout << "\nPublic Key (e, n): (" << e << ", " << n << ")";
    cout << "\nPrivate Key (d, n): (" << d << ", " << n << ")\n";

    int msg;
    cout << "\nEnter message (integer): ";
    cin >> msg;

    // Encryption: c = (msg^e) % n
    long long cipher = power(msg, e, n);
    cout << "Encrypted message: " << cipher << endl;

    // Decryption: m = (cipher^d) % n
    long long decrypted = power(cipher, d, n);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}