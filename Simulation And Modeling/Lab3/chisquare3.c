//Activity2: Implementation of testing of uniformity of random numbers using chi-square test.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SEED 35791246

int main()
{
    int N,n,i;
    double expected,chi=0,table;

    printf("Enter sample size: ");
    scanf("%d",&N);

    printf("Enter number of intervals: ");
    scanf("%d",&n);

    printf("Enter tabulated chi-square value: ");
    scanf("%lf",&table);

    int observed[n];

    for(i=0;i<n;i++)
        observed[i]=0;

    srand(SEED);

    for(i=0;i<N;i++)
    {
        double r=(double)rand()/RAND_MAX;
        int index=r*n;
        if(index==n) index=n-1;
        observed[index]++;
    }

    expected=(double)N/n;

    printf("\nOi\tEi\tOi-Ei\t(Oi-Ei)^2/Ei\n");

    for(i=0;i<n;i++)
    {
        double diff=observed[i]-expected;
        double value=(diff*diff)/expected;

        printf("%d\t%.2f\t%.2f\t%.2f\n",observed[i],expected,diff,value);

        chi=chi+value;
    }

    printf("\nCalculated Chi-square = %.2f\n",chi);

    if(chi<table)
    {
        printf("Null Hypothesis Accepted\n");
        printf("Uniform Distribution\n");
    }
    else
    {
        printf("Null Hypothesis Rejected\n");
        printf("Not Uniform Distribution\n");
    }

    return 0;
}
