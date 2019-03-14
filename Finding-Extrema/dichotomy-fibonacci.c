#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f (float x)
{
    return 4*x*x+16/x;
}

int main()
{
    const float a=1.0;
    const float b=5.0;
    const float e=0.01;
    float a1=1.0;
    float b1=5.0;
    float x1;
    float x2;
    float x3;
    float f1;
    float f2;
    float fib1=1;
    float fib2=1;
    float fib3=2;
    float fib0;
    char parbaudeArg[]="1.259921";
    char parbaudeFja[]="19.048813";
    int i=0;
    int j;
    int izvele;
    printf("Choose a method for finding extrema:\n");
    printf("   1 - the dichotomy method;\n   2 - the Fibonacci method;\nYour choice is: ");
    scanf("%d",&izvele);

    switch (izvele)
    {
        case 1:
        printf("\n\nDichotomy\n\nInterval [1;5]\nPrecision e=0.01\n\n");
        while (fabs(b1-a1)>2*e)
        {
            x1=(a1+b1)/2-e/2;
            x2=(a1+b1)/2+e/2;
            if (f(x1)>=f(x2))
            {
                a1=x1;
                i++;
            }
            else
            {
                b1=x2;
                i++;
            }
        }
        printf("Value of the argument at the extremum: %f\n",(a1+b1)/2);
        printf("Result obtained with Mathematica:             %s\n",parbaudeArg);
        printf("Value of the function at the extremum: %f\n",f((a1+b1)/2));
        printf("Result obtained with Mathematica:             %s\n",parbaudeFja);
        printf("Number of steps:                       %d\n",i);
        break;

        case 2:
        printf("\n\nFibonacci method\n\nInterval [1;5]\nPrecision e=0.01\n\n");
        i=0;
        while (fib3<=(b-a)/e)
        {
            fib0=fib3;
            fib3=fib1+fib2;
            fib1=fib2;
            fib2=fib0;
            i++;
        }

        x2=a*fib2/fib3+b*fib1/fib3;
        x1=a+b-x2;
        f1=f(x1);
        f2=f(x2);
        a1=a;
        b1=b;

        for (j=1;j<=i;j++)
        {
            if (f1<=f2)
            {
                b1=x2;
                x2=x1;
                f2=f1;
                x1=a1+b1-x2;
                f1=f(x1);
                if (x1>x2)
                {
                    x3=x1;
                    x1=x2;
                    x2=x3;
                    f1=f(x1);
                    f2=f(x2);
                }
            }
            else
            {
                a1=x1;
                x1=x2;
                f1=f2;
                x2=a1+b1-x1;
                f2=f(x2);
                if (x1>x2)
                {
                    x3=x1;
                    x1=x2;
                    x2=x3;
                    f1=f(x1);
                    f2=f(x2);
                }
            }
        }
        printf("Value of the argument at the extremum: %f\n",(a1+b1)/2);
        printf("Result obtained with Mathematica:             %s\n",parbaudeArg);
        printf("Value of the function at the extremum: %f\n",f((a1+b1)/2));
        printf("Result obtained with Mathematica:             %s\n",parbaudeFja);
        printf("Number of steps:                       %d\n",i);
        break;
        default:
        printf("\nYou havent chosen any of the methods\n");
    }

    return 0;
}
