// Lab-2: Random Number Generation using Linear Congruential Method (LCM)

#include<stdio.h>

int main(){
    int n,a,c,m,r[100];

    printf("Enter how many random numbers to generate: ");
    scanf("%d",&n);

    printf("Enter seed value (R0): ");
    scanf("%d",&r[0]);

    printf("Enter value of a (multiplier): ");
    scanf("%d",&a);

    printf("Enter value of c (increment): ");
    scanf("%d",&c);

    printf("Enter value of m (modulus): ");
    scanf("%d",&m);

    // Linear Congruential Formula
    // R(i+1) = (a * R(i) + c) mod m

    for(int i=0;i<n;i++){
        r[i+1] = ((r[i] * a) + c) % m;
    }

    printf("\nRandom numbers generated are:\n");

    for(int i=0;i<n;i++){
        printf("%d ", r[i]);
    }

    printf("\nName:Anil Pal Roll no:5");
    return 0;
}
