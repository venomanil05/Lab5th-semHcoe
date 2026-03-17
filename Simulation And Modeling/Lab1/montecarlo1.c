//calculate the value of pi using monte carlo method
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#define SEED 35791246
#define PI 3.14159265358979323846

int main()
{
    int N=0;
    double x,y;
    int i ,n=0;
    double z;
    double pi;
    double error_percentage;
    printf("Monte Carlo Method Lab1 Q1\n");
    printf("Enter the number of iterations used to estimate pi: ");
    scanf("%d",&N);
    srand(SEED);
    n=0;

    for(i=0;i<N;i++)
    {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        z=x*x+y*y;
        if (z<=1)
            n++;
    }
    pi = (double) n / N * 4;
    error_percentage = fabs((pi - PI) / PI) * 100;
    printf("No of trials = %d, estimate of pi is %g\n", N, pi);
    printf("Error percentage: %.2f%%\n", error_percentage);
   printf("Name:Anil Pal Roll:5");
    getch();
}
