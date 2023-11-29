#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

// Function to generate a random prime number
int generateRandomPrime(int min, int max) {
    int num;
    do {
        num = rand() % (max - min + 1) + min;
    } while (!isPrime(num));
    return num;
}

// Function to calculate the modular inverse
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return 1;
}

// Function to generate RSA key pair
void generateRSAKeys(int& publicKey, int& privateKey, int& n) {
    srand(time(0));

    // Choose two distinct prime numbers
    int p = generateRandomPrime(100, 200);
    int q = generateRandomPrime(200, 300);

    // Calculate n and Euler's totient function
    n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose public key e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    publicKey = generateRandomPrime(2, phi - 1);

    // Calculate private key d such that (d * e) % phi(n) = 1
    privateKey = modInverse(publicKey, phi);
}

// Function to encrypt a message using RSA public key
int encrypt(int message, int publicKey, int n) {
    return (int)pow(message, publicKey) % n;
}

// Function to decrypt a ciphertext using RSA private key
int decrypt(int ciphertext, int privateKey, int n) {
    return (int)pow(ciphertext, privateKey) % n;
}

int main() {
    int publicKey, privateKey, n;

    // Generate RSA key pair
    generateRSAKeys(publicKey, privateKey, n);

    // Example message to encrypt
    int message;
    cout << "Enter message: ";
    cin >> message;

    // Encrypt using the public key
    int ciphertext = encrypt(message, publicKey, n);

    cout << "Original Message: " << message << endl;
    cout << "Encrypted Message: " << ciphertext << endl;

    // Decrypt using the private key
    int decryptedMessage = decrypt(ciphertext, privateKey, n);

    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}






