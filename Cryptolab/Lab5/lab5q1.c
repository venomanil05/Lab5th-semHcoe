// Lab-5 Primality testing, totient function and primitive root
//1.Write a C program to test whether given number is prime or not using Millar-Robin algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Modular exponentiation function
long long mod_pow(long long a, long long b, long long n) {
    long long result = 1;
    a %= n;
    while (b > 0) {
        if (b % 2) result = (result * a) % n;
        a = (a * a) % n;
        b /= 2;
    }
    return result;
}

int main() {
    long long n, d, a, x;
    int k = 0;

    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    if (n <= 1) { printf("%lld is not Prime\n", n); return 0; }
    if (n <= 3) { printf("%lld is prime\n", n); return 0; }

    // Step 1: Factor n-1 as 2^k * d
    d = n - 1;
    while (d % 2 == 0) { d /= 2; k++; }
    printf("\nStep 1: Factor n-1\n");
    printf("n-1 = 2^k * d\n");
    printf("%lld - 1 = 2^%d * %lld\n", n, k, d);

    // Step 2: Select random base a
    srand(time(NULL));
    a = 2 + rand() % (n - 3); // 2 <= a <= n-2
    printf("\nStep 2: Select random base a\n");
    printf("Random a = %lld\n", a);

    // Calculate x = a^d mod n
    x = mod_pow(a, d, n);
    printf("Calculate x = a^d mod n\n");
    printf("x = %lld^%lld mod %lld = %lld\n", a, d, n, x);

    // Miller-Rabin test
    if (x == 1 || x == n - 1) {
        printf("\nResult: %lld is  prime\n", n);
        return 0;
    }

    for (int i = 0; i < k - 1; i++) {
        x = (x * x) % n;
        printf("Step %d: x = x^2 mod n = %lld\n", i + 3, x);
        if (x == n - 1) {
            printf("\nResult: %lld is prime\n", n);
             printf("Name:Anil Pal   Roll no:5");
            return 0;
        }
    }

    printf("\nResult: %lld is not Prime\n", n);
     printf("Name:Anil Pal   Roll no:5");
    return 0;
}
