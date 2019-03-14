#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Pi 3.141592653589793

float f (float x)
{
    return exp(-cos(x))*cos(sin(x));
}

float integralis (float a, float b, int n)
{
    float x;
    float sum;

    sum=0;
    for (x=a;x<b;x=x+((b-a)/n))
    {
        sum=sum+f(x+(b-a)/n)*(b-a)/n;
    }
    return sum;
}
int main()
{
    float mathematica[]={0.624713, 0.717206, 0.82928, 0.968449, 1.14308, 1.36123, 1.62893, 1.94809, \
                        2.31471, 2.71809, 3.14159};
    float k;
    float e=0.01;
    int n;
    int i;
    float rezultati[11];
    int solji[11];

    i=0;

    for (k=0;k<=Pi/2;k=k+Pi/20)
    {
        n=20;
        while (fabs(integralis(0,Pi/2+k,n)-(integralis(0,Pi/2+k,n/2)))>=e)
            n=2*n;
        rezultati[i]=integralis(0,Pi/2+k,n);
        solji[i]=n;
        i++;
    }

    printf("Right Riemann sum\n\n");
    printf("No\ta\tb\tIntegral\tMathematica\tn-dal\n");

    for (i=0;i<=10;i++)
    {
        printf("%d\t%d\t%f\t%f\t%f\t%d\n",i+1,0,Pi/2+Pi*i/20,rezultati[i],mathematica[i],solji[i]);
    }

    printf("\nPrecision e=0.01\n");

    return 0;
}
