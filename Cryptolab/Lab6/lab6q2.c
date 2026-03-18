//2. Write a C program to implement RSA Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function for modular exponentiation
int modulo(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int p, q, n, phi, e, d, message;

    printf("Enter two prime numbers: ");
    scanf("%d%d", &p, &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Find e (public exponent)
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) break;
    }

    // Find d (private exponent)
    for (d = 2; d < phi; d++) {
        if ((e * d) % phi == 1) break;
    }

    // Display public and private key
    printf("\nPublic key (n, e) = (%d, %d)\n", n, e);
    printf("Private key (n, d) = (%d, %d)\n", n, d);

    // Input message
    printf("Enter the message (integer < %d): ", n);
    scanf("%d", &message);

    // Encryption
    int cipher = modulo(message, e, n);
    printf("Encrypted message: %d\n", cipher);

    // Decryption
    int decrypted = modulo(cipher, d, n);
    printf("Decrypted message: %d\n", decrypted);

    printf("Name: Anil Pal   Roll no: 5\n");

    return 0;
}
