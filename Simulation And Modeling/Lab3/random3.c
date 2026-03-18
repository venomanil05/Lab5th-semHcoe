//Activity3:generate the n random numbers using LCM and test the uniformity of generated number using chi-square method. before doing calculation of chi be sure that your generator has generated minimum 40 numbers.
#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    long int X0, a, c, m;
    double random[1000];

    printf("------LCM Random Number Generator------\n");
    printf("Enter number of random numbers to generate (>=40): ");
    scanf("%d", &n);

    if(n < 40) {
        printf("Number of random numbers must be at least 40.\n");
        return 0;
    }

    printf("Enter seed value (X0): ");
    scanf("%ld", &X0);
    printf("Enter multiplier (a): ");
    scanf("%ld", &a);
    printf("Enter increment (c): ");
    scanf("%ld", &c);
    printf("Enter modulus (m): ");
    scanf("%ld", &m);

    // Generate random numbers using LCM
    printf("\nGenerated Random Numbers:\n");
    for(i = 0; i < n; i++) {
        X0 = (a * X0 + c) % m;
        random[i] = (double)X0 / m;
        printf("%0.4lf ", random[i]);
        if((i+1) % 10 == 0) printf("\n");
    }

    // Determine number of intervals using Sturges' formula
    int k = (int)(1 + 3.322 * log10(n));
    if(k < 5) k = 5; // minimum 5 intervals

    int freq[k];
    for(i = 0; i < k; i++) freq[i] = 0;

    // Count numbers in each interval
    for(i = 0; i < n; i++) {
        int interval = (int)(random[i] * k);
        if(interval == k) interval = k-1;
        freq[interval]++;
    }

    // Display table
    double expected = (double)n / k;
    double chi_square = 0;
    printf("\nInterval\tObserved\tExpected\t(O-E)^2/E\n");
    for(i = 0; i < k; i++) {
        double diff = (freq[i] - expected);
        chi_square += (diff * diff) / expected;
        printf("%d\t\t%d\t\t%.2lf\t\t%.4lf\n", i+1, freq[i], expected, (diff*diff)/expected);
    }

    printf("\nChi-square value = %0.4lf\n", chi_square);
    printf("Degrees of freedom = %d\n", k-1);
    printf("Compare this with Chi-square table value at 0.05 significance.\n");

    return 0;
}
