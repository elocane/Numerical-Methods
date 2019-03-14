#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f (float x)
{
    return x+6*cos(3*cos(x));
}

int main()
{
    float mathMax[3]={1.5893286,4.7309213,7.87251394};
    float mathMin[2]={2.8966450,6.0382377};
    char string[50];
    float n100min[2];
    float n100max[3];
    float n1000min[2];
    float n1000max[3];
    float a=1;
    float b=9;
    float x1;
    float x2;
    float x3;
    float f1;
    float f2;
    float f3;
    float h;
    int n=100;
    int i=0;
    int j=0;

    h=(b-a)/n;
    x1=a;
    x2=a+h;
    f1=f(x1);
    f2=f(x2);

    do
    {
        x3=x2+h;
        f3=f(x3);
        if ((f3-f2)*(f2-f1)<0)
        {
            if (f2<f1)
            {
                n100min[i++]=x1+h/2*(3*f1-4*f2+f3)/(f1-2*f2+f3);
            }
            else
            {
                n100max[j++]=x1+h/2*(3*f1-4*f2+f3)/(f1-2*f2+f3);
            }
        }
        x1=x2;
        x2=x3;
        f1=f2;
        f2=f3;
    }
    while (x3<b);

    sprintf(string,"Uniform search\n\n n=100\nEkstremum\tArgument\tFunction\tMathematica\n");
    puts(string);
    for (i=0;i<=2;i++)
    {
        sprintf(string,"Maximum\t%f\t%f\t%f",n100max[i],f(n100max[i]),mathMax[i]);
        puts(string);
    }

     for (i=0;i<=1;i++)
    {
        sprintf(string,"Minimum\t%f\t%f\t%f",n100min[i],f(n100min[i]),mathMin[i]);
        puts(string);
    }

    i=j=0;
    n=1000;
    h=(b-a)/n;
    x1=a;
    x2=a+h;
    f1=f(x1);
    f2=f(x2);

    do
    {
        x3=x2+h;
        f3=f(x3);
        if ((f3-f2)*(f2-f1)<0)
        {
            if (f2<f1)
            {
                n1000min[i++]=x1+h/2*(3*f1-4*f2+f3)/(f1-2*f2+f3);
            }
            else
            {
                n1000max[j++]=x1+h/2*(3*f1-4*f2+f3)/(f1-2*f2+f3);
            }
        }
        x1=x2;
        x2=x3;
        f1=f2;
        f2=f3;
    }
    while (x3<b);

    sprintf(string,"\n\n n=1000\nEkstremum\tArgument\tFunction\tMathematica\n");
    puts(string);

    for (i=0;i<=2;i++)
    {
        sprintf(string,"Maximum\t%f\t%f\t%f",n1000max[i],f(n1000max[i]),mathMax[i]);
        puts(string);
    }

     for (i=0;i<=1;i++)
    {
        sprintf(string,"Minimum\t%f\t%f\t%f",n1000min[i],f(n1000min[i]),mathMin[i]);
        puts(string);
    }

    return 0;
}
