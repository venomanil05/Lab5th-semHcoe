//Activity2:Finding Cycle Length Modify the above program(activity1)and find the cycle length.once you identify there is present of same random number
//as given in seed.you have to terminate your program.
#include<stdio.h>
int main() {
    int a, c, m, r[100], i = 0, n;

    printf("Enter how many random numbers to generate: ");
    scanf("%d",&n);

    printf("Enter seed value (R0): ");
    scanf("%d", &r[0]);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of c: ");
    scanf("%d", &c);

    printf("Enter value of m: ");
    scanf("%d", &m);

    do {
        r[i+1] = (r[i] * a + c) % m;
        i++;
    } while (r[i] != r[0] && i < n);

    printf("\nGenerated Random Numbers:\n");

    for (int j = 0; j <= i; j++) {
        printf("%d ", r[j]);
    }

    printf("\nCycle Length = %d\n", i);
   printf("Name:Anil Pal   Roll no:5");
    return 0;
}
