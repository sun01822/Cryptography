#include <iostream>
#include <cmath>

using namespace std;

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return 1;
}

int decrypt(int ciphertext, int privateKey, int n) {
    return static_cast<int>(pow(ciphertext, privateKey)) % n;
}

int main() {
    int privateKey, n, ciphertext;

    cout << "Enter private key: ";
    cin >> privateKey;

    cout << "Enter modulus (n): ";
    cin >> n;

    cout << "Enter ciphertext to decrypt: ";
    cin >> ciphertext;

    int decryptedMessage = decrypt(ciphertext, privateKey, n);

    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}

