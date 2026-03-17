#include <stdio.h>

int main()
{
    int total_experiments, successful_experiments;
    float probability;

    printf("Enter total number of experiments: ");
    scanf("%d", &total_experiments);

    printf("Enter number of successful experiments (3,6 or 9 heads cases): ");
    scanf("%d", &successful_experiments);

    probability = (float)successful_experiments / total_experiments;

    printf("\nTotal Experiments = %d", total_experiments);
    printf("\nSuccessful Experiments = %d", successful_experiments);
    printf("\nEstimated Probability = %f", probability);

    printf("\n\nName: Anil Pal  Roll no:5");

    return 0;
}
