#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define root -0.2876820724517809

float f (float x)
{
    return exp(x)+sqrt(1+exp(2*x))-2;
}

float d (float x)
{
    return exp(x)+exp(2*x)/sqrt(1+exp(2*x));
}
int main()
{
    float e;
    float x1=0;
    float x2=0;
    float x3=-1;
    int i=0;

    printf("Newthons method\n\n");
    printf("Choose precision e=");
    scanf("%f",&e);

    while (fabs(x3-x2)>e)
    {
            x2=x1-f(x1)/d(x1);
            x3=x1;
            x1=x2;
            i++;
    }

    printf("\nObtained root: %f\n",x2);
    printf("Number of steps N=          %d\n",i);
    printf("Benchmark value:     %f\n",root);

    return 0;
}
