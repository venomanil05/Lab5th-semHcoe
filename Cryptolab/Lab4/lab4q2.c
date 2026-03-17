//multiplicative inverse of any number in Zn using extended euclidean algorithm
#include<stdio.h>

int main(){
    int r1,n,b,r2,t1=0,t2=1,q,r,t,inverse;
    printf("Lab4Q2");
    printf("Enter modulus n: ");
    scanf("%d",&n);

    printf("Enter number to find multiplicative inverse: ");
    scanf("%d",&b);

    r1=n;
    r2=b;

    printf("\nStep\tr1\tr2\tq\tr\tt1\tt2\tt\n");

    int step=1;

    while(r2>0){
        q=r1/r2;
        r=r1-q*r2;

        t=t1-q*t2;

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",step,r1,r2,q,r,t1,t2,t);

        r1=r2;
        r2=r;

        t1=t2;
        t2=t;

        step++;
    }

    if(r1!=1){
        printf("\nMultiplicative inverse does not exist.\n");
    }
    else{
        inverse=t1%n;
        if(inverse<0)
            inverse=inverse+n;

        printf("\nThe multiplicative inverse of %d is %d\n",b,inverse);
    }

    printf("\nName: Anil Pal  Roll:5");
    return 0;
}
