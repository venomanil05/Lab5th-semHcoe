// Activity1:Chi-Square Test for Uniform Distribution
#include<stdio.h>
#include<math.h>

int main()
{
    int k,i;
    float O[20],E,n=0,chi=0,tab;

    printf("Enter number of classes: ");
    scanf("%d",&k);

    printf("Enter tabulated chi-square value: ");
    scanf("%f",&tab);

    printf("Enter observed frequencies:\n");
    for(i=0;i<k;i++)
    {
        scanf("%f",&O[i]);
        n=n+O[i];
    }

    E=n/k;

    printf("\nOi\tEi\tOi-Ei\t(Oi-Ei)^2/Ei\n");

    for(i=0;i<k;i++)
    {
        float diff=O[i]-E;
        float value=(diff*diff)/E;

        printf("%.0f\t%.2f\t%.2f\t%.2f\n",O[i],E,diff,value);

        chi=chi+value;
    }

    printf("\nCalculated Chi-square = %.2f\n",chi);

    if(chi < tab)
    {
        printf("Null Hypothesis Accepted\n");
        printf("Random numbers are Uniformly Distributed\n");
    }
    else
    {
        printf("Null Hypothesis Rejected\n");
        printf("Random numbers are NOT Uniformly Distributed\n");
    }

    return 0;
}
