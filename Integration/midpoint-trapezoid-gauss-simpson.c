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

float trapecu (float a, float b, int n)
{
    float sum=0;
    float h=(b-a)/n;
    int i;

    for (i=0;i<n;i++)
        sum=sum+(f(a+i*h)/2+f(a+(i+1)*h)/2)*h;

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

float simpsona4p (float a, float b, int n)
{
    float sum=0;
    float h=(b-a)/n;
    int i;

    for (i=0;i<n;i++)
        sum=sum+h*(f(a+i*h)/8+3*f(a+i*h+h/3)/8+3*f(a+i*h+2*h/3)/8+f(a+h*(i+1))/8);

    return sum;
}

float gausa3p (float a, float b, int n)
{
    float sum=0;
    float h=(b-a)/n;
    int i;

    for (i=0;i<n;i++)
        sum=sum+h*(5*f(a+i*h+((5-sqrt(15))/10)*h)/18+8*f(a+h*i+h/2)/18+5*f(a+i*h+((5+sqrt(15))/10)*h)/18);

    return sum;
}

int main()
{
    float mathematica[]={0.624713, 0.717206, 0.82928, 0.968449, 1.14308, 1.36123, 1.62893, 1.94809, 2.31471, 2.71809, 3.14159};
    const float e=0.01;
    int n;
    int i;
    const float a=0;
    const float b=Pi/2;
    const float h=Pi/20;
    float rezultati[11][6];
    int solji[11][6];

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

    for (i=0;i<=10;i++)
    {
        n=20;
        while (fabs(trapecu(a,b+h*i,n)-(trapecu(a,b+h*i,n/2)))>=e)
            n=2*n;
        rezultati[i][3]=trapecu(a,b+h*i,n);
        solji[i][3]=n;
    }

    for (i=0;i<=10;i++)
    {
        n=20;
        while (fabs(simpsona4p(a,b+h*i,n)-(simpsona4p(a,b+h*i,n/2)))>=e)
            n=2*n;
        rezultati[i][4]=simpsona4p(a,b+h*i,n);
        solji[i][4]=n;
    }

    for (i=0;i<=10;i++)
    {
        n=20;
        while (fabs(gausa3p(a,b+h*i,n)-(gausa3p(a,b+h*i,n/2)))>=e)
            n=2*n;
        rezultati[i][5]=gausa3p(a,b+h*i,n);
        solji[i][5]=n;
    }

    printf("Numerical integration\n\nPrecision e=0.01\nResults:\n\n");
    printf(" Nr a    b\tMidpoint\tSimpson\tSimpson 3/8\tMathematica\n\n");

    for (i=0;i<=10;i++)
    {
        printf("%2d  %d\t%3.2f\t%f\t%f\t%f\t%f\n",i+1,0,Pi/2+Pi*i/20,rezultati[i][0],rezultati[i][1],rezultati[i][4],mathematica[i]);
    }

    printf("\n Nr a    b\tTrapezoid\t\tGauss 2p\tGauss 3p\tMathematica\n\n");

    for (i=0;i<=10;i++)
    {
        printf("%2d  %d\t%3.2f\t%f\t%f\t%f\t%f\n",i+1,0,Pi/2+Pi*i/20,rezultati[i][3],rezultati[i][2],rezultati[i][5],mathematica[i]);
    }

    printf("\n\nDalijumu skaits:\n\n");
    printf(" Nr a    b\tMidpoint\tSimpson\tSimpson 3/8\n\n");

    for (i=0;i<=10;i++)
    {
        printf("%2d  %d\t%3.2f\t   %d\t\t  %d\t\t %d\n",i+1,0,Pi/2+Pi*i/20,solji[i][0],solji[i][1],solji[i][4]);
    }

    printf("\n Nr a    b\tTrapezoid\t\tGauss 2p\tGauss 3p\n\n");

    for (i=0;i<=10;i++)
    {
        printf("%2d  %d\t%3.2f\t   %d\t\t  %d\t\t %d\n",i+1,0,Pi/2+Pi*i/20,solji[i][3],solji[i][2],solji[i][5]);
    }

    return 0;
}
