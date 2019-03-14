#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "defin.h"
#include "dihotomija.h"
#include "fibonaci.h"
#include "zeltagr.h"

int main()
{
    char string[256];
    float min;

    sprintf(string,"Finding a minimum\n\ne=0.01\nMethod\t\tArgument\tFunction\tNo of calcul.\tMathematica\n");
    puts(string);

    e=0.01;
    min=dihotomija(e);
    sprintf(string,"Dichotomy\t%f\t%f\t%d\t\t%s",min,f(min),i,parbaudeArg);
    puts(string);

    min=fibonaci(e);
    sprintf(string,"Fibonacci\t%f\t%f\t%d\t\t%s",min,f(min),i,parbaudeArg);
    puts(string);

    min=zeltagr(e);
    sprintf(string,"Golden section\t%f\t%f\t%d\t\t%s",min,f(min),i,parbaudeArg);
    puts(string);

    //e=0.001
    sprintf(string,"\n\ne=0.001\nMethod\t\tArgument\tFunction\tNo of calcul.\tMathematica\n");
    puts(string);

    e=0.001;
    min=dihotomija(e);
    sprintf(string,"Dichotomy\t%f\t%f\t%d\t\t%s",min,f(min),i,parbaudeArg);
    puts(string);

    min=fibonaci(e);
    sprintf(string,"Fibonacci\t%f\t%f\t%d\t\t%s",min,f(min),i,parbaudeArg);
    puts(string);

    min=zeltagr(e);
    sprintf(string,"Golden section\t%f\t%f\t%d\t\t%s",min,f(min),i,parbaudeArg);
    puts(string);

    return 0;
}
