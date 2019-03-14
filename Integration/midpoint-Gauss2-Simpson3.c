#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Pi 3.141592653589793

float f (float x)
{
    return exp(-cos(x))*cos(sin(x));
}

float centrala (float a, float b, int n)
{
    float sum=0;
    float h=(b-a)/n;
    int i;

    for (i=0;i<n;i++)
        sum=sum+f(a+i*h+h/2)*h;

    return sum;
}

float simpsona3p (float a, float b, int n)
{
    float sum=0;
    float h=(b-a)/n;
    int i;

    for (i=0;i<n;i++)
        sum=sum+h*(f(a+i*h)/6+2*f(a+i*h+h/2)/3+f(a+h*(i+1))/6);

    return sum;
}

float gausa2p (float a, float b, int n)
{
    float sum=0;
    float h=(b-a)/n;
    int i;

    for (i=0;i<n;i++)
        sum=sum+h*(f(a+i*h+((3.0-sqrt(3))/6.0)*h)/2+f(a+i*h+((3.0+sqrt(3))/6.0)*h)/2);

    return sum;
}

int main()
{
    float mathematica[]={0.624713, 0.717206, 0.82928, 0.968449, 1.14308, 1.36123, 1.62893, 1.94809, \
                        2.31471, 2.71809, 3.14159};
    const float e=0.01;
    int n;
    int i;
    int j;
    const float a=0;
    const float b=Pi/2;
    const float h=Pi/20;
    float rezultati[11][3];
    int solji[11][3];

    for (i=0;i<=10;i++)
    {
        n=20;
        while (fabs(centrala(a,b+h*i,n)-(centrala(a,b+h*i,n/2)))>=e)
            n=2*n;
        rezultati[i][0]=centrala(a,b+h*i,n);
        solji[i][0]=n;
    }

    for (i=0;i<=10;i++)
    {
        n=20;
        while (fabs(simpsona3p(a,b+h*i,n)-(simpsona3p(a,b+h*i,n/2)))>=e)
            n=2*n;
        rezultati[i][1]=simpsona3p(a,b+h*i,n);
        solji[i][1]=n;
    }

    for (i=0;i<=10;i++)
    {
        n=20;
        while (fabs(gausa2p(a,b+h*i,n)-(gausa2p(a,b+h*i,n/2)))>=e)
            n=2*n;
        rezultati[i][2]=gausa2p(a,b+h*i,n);
        solji[i][2]=n;
    }

    printf("Numerical integration\n\nPrecision e=0.01\nResults:\n\n");
    printf(" No a    b\tMidpoint\tSimpson\tGauss\t\tMathematica\n\n");

    for (i=0;i<=10;i++)
    {
        printf("%2d  %d\t%3.2f\t%f\t%f\t%f\t%f\n",i+1,0,Pi/2+Pi*i/20,rezultati[i][0],rezultati[i][1],rezultati[i][2],mathematica[i]);
    }

    printf("\n\nNo of divisions:\n\n");
    printf(" Nr a    b\tMidpoint\tSimpson\tGauss\n\n");

    for (i=0;i<=10;i++)
    {
        printf("%2d  %d\t%3.2f\t   %d\t\t  %d\t\t %d\n",i+1,0,Pi/2+Pi*i/20,solji[i][0],solji[i][1],solji[i][2]);
    }

    return 0;
}
