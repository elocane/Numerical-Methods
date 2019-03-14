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

float g (float x)
{
    return log(2-sqrt(1+exp(2*x)));
}

float dg (float x)
{
    return -exp(2*x)/(sqrt(1+exp(2*x))*(2-sqrt(1+exp(2*x))));
}

int main()
{
    float a=-1;
    float b=0;
    float c;
    float e;
    float x1=0;
    float x2=0;
    float x3=-1;
    int i=0;
    float w=0.6;

    printf("Choose precision e=");
    scanf("%f",&e);
    printf("Interval [-1;0]\n");
    printf("Benchmark value: %f\n\n",root);

    while (fabs(a-b)>=2*e)
    {
        c=(a+b)/2;
        if (f(a)*f(c)<=0)
        {
            b=c;
        }
        else
        {
            a=c;
        }
        i++;
    }
    printf("     Bisection method\nRoot:             %f\nNumber of steps:        %d",(a+b)/2,i);


    i=0;
     while (fabs(x3-x2)>e)
    {
            x2=x1-f(x1)/d(x1);
            x3=x1;
            x1=x2;
            i++;
    }
    printf("\n        -------\n     Newtons method\nRoot:             %f\nNumber of steps:        %d",x2,i);

    x1=0;
    x2=-1;
    i=0;
    while (fabs(x2-x1)>e) //secant method
    {
        x3=x2-f(x2)/((f(x2)-f(x1))/(x2-x1));
        x1=x2;
        x2=x3;
        i++;
    }
    printf("\n        -------\n     Secant method\nRoot:             %f\nNumber of steps:        %d",x3,i);

    i=0;
    x1=0;
    x2=-1;
    x3=0;
    while (fabs(x2-x3)>fabs(e*w*(1-dg(x1))))
        {
            x2=x1+w*(g(x1)-x1);
            x3=x1;
            x1=x2;
            i++;
        }
    printf("\n        -------\n     Fixed-point iteration (w=0.6)\nRoot:             %f\nNumber of steps:        %d\n\n",x2,i);

    return 0;
}
