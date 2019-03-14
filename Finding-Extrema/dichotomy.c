#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f (float x)
{
    return cos(3*x)+sinh(x);
}

int main()
{
    float a;
    float b;
    float e;
    float x1;
    float x2;
    char parbaudeArg[]="1.259921";
    char parbaudeFja[]="19.048813";

    a=-1.65;
    b=-0.5;
    e=0.0001;

    while (fabs(b-a)>2*e)
    {
        x1=(a+b)/2-e/2;
        x2=(a+b)/2+e/2;
        if (f(x1)>=f(x2))
            a=x1;
        else
            b=x2;
    }

    printf("Minimum value obtained with the dichotomy method: %f\n",f((a+b)/2));
    printf("Minimum value obtained with Mathematica:        %s\n\n",parbaudeFja);
    printf("Value of the argument at the minimum:                              %f\n",(a+b)/2);
    printf("Value of the argument obtained with Mathematica:        %s\n\n",parbaudeArg);
    printf("The interval considered is [1;5], precision is:                    %f\n",e);

    return 0;
}
