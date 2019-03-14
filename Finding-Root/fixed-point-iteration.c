#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define root -0.2876820724517809

float g (float x)
{
    return log(2-sqrt(1+exp(2*x)));
}

float d (float x)
{
    return -exp(2*x)/(sqrt(1+exp(2*x))*(2-sqrt(1+exp(2*x))));
}
int main()
{
    float e;
    float x1;
    float x2;
    float x3;
    int i;
    float w=0.1;

    printf("Fixed-point iteration \n\n");
    printf("Choose precision e=");
    scanf("%f",&e);

    printf("Rel. coeff.\tResult\tMathematica\tNo of steps\n\n");

    while (w<2.0)
    {
        i=0;
        x1=x3=0;
        x2=-1;
        while (fabs(x2-x3)>fabs(e*w*(1-d(x1))))
        {
            x2=x1+w*(g(x1)-x1);
            x3=x1;
            x1=x2;
            i++;
        }
        printf("%.1f\t\t%f\t%f\t%d\n",w,x2,root,i);
        w+=0.1;
    }

    return 0;
}
