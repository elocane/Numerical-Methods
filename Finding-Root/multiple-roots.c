#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define root1 -2.930870466348223
#define root2 -2.1907383045273336
#define root3 -1.029128793874574
#define root4 0.000000
#define root5 1.066672131215094
#define root6 2.0155452593667684

float f (float x)
{
    return sin(3*x)+0.2*cosh(0.7*x)-0.2;
}

int main()
{
    float a=-10;
    float b=10;
    float a1;
    float b1;
    float h=1.0;
    float e=0.01;
    float x;
    float c;
    int i;

    printf("Finding multiple roots\nInterval [-10;10]\n\nStep h=1.0\nPrecision e=0.01\n\n");

    x=a;
    while (x<b)
    {
        if (f(x)*f(x+h)<=0)
        {
            i=0;
            a1=x;
            b1=x+h;
            while (fabs(a1-b1)>=2*e)
            {
                c=(a1+b1)/2;
                if (f(a1)*f(c)<=0)
                    b1=c;
                else
                    a1=c;
                i++;
            }
            printf("Found root: %f\nNumber of steps:    %d\n\n",(a1+b1)/2,i);
            x=x+h;
        }
        else
            x=x+h;
    }

    printf("Benchmark values:  %f\n                     %f\n                     %f\n                      %f\n                      %f\n                      %f\n\n",root1,root2,root3,root4,root5,root6);
    printf("Step h=0.1\nPrecision e=0.0001\n\n");

    h=0.1;
    e=0.0001;
    x=a;
    while (x<b)
    {
        if (f(x)*f(x+h)<=0)
        {
            i=0;
            a1=x;
            b1=x+h;
            while (fabs(a1-b1)>=2*e)
            {
                c=(a1+b1)/2;
                if (f(a1)*f(c)<=0)
                    b1=c;
                else
                    a1=c;
                i++;
            }
            printf("Found root: %f\nNumber of steps:    %d\n\n",(a1+b1)/2,i);
            x=x+h;
        }
        else
            x=x+h;
    }

    printf("Benchmark values:  %f\n                     %f\n                     %f\n                      %f\n                      %f\n                      %f\n\n",root1,root2,root3,root4,root5,root6);
    return 0;
}
