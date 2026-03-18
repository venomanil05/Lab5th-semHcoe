//3. Write a C program to find primitive root of any prime number.

#include <stdio.h>

// Function to calculate a^i mod p
int Power(int a, int i, int p) {
    int result = 1;
    for (int j = 0; j < i; j++) {
        result = (result * a) % p;
    }
    return result;
}

int main() {
    int a, p;
    printf("Enter a prime number p: ");
    scanf("%d", &p);

    printf("Enter a number a (less than p) to check if it is a primitive root: ");
    scanf("%d", &a);

    int res[p-1]; // array to store a^i mod p
    int isPrimitive = 1; // flag to check

    printf("\nCalculating a^i mod p for i = 1 to p-1:\n");
    for (int i = 1; i < p; i++) {
        res[i-1] = Power(a, i, p);
        printf("a^%d mod %d = %d\n", i, p, res[i-1]);
    }
    // Check for duplicates
    for (int i = 0; i < p-1; i++) {
        for (int j = 0; j < i; j++) {
            if (res[i] == res[j]) {
                isPrimitive = 0;
                break;
            }
        }
        if (!isPrimitive) break;
    }

    if (isPrimitive)
        printf("\n%d is a primitive root of %d.\n", a, p);
    else
        printf("\n%d is NOT a primitive root of %d.\n", a, p);

    printf("\nName: Anil Pal   Roll no: 5\n");
    return 0;
}
