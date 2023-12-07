#include <iostream>
#include <cmath>

using namespace std;

int encrypt(int message, int publicKey, int n) {
    return static_cast<int>(pow(message, publicKey)) % n;
}

int main() {
    int publicKey, n, message;

    cout << "Enter public key: ";
    cin >> publicKey;

    cout << "Enter modulus (n): ";
    cin >> n;

    cout << "Enter message to encrypt: ";
    cin >> message;

    int ciphertext = encrypt(message, publicKey, n);

    cout << "Encrypted Message: " << ciphertext << endl;

    return 0;
}
