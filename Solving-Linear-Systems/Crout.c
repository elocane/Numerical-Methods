#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float m[5][5];
    float y[5];
    float x[5];
    float mathematica[3]={1.23,2.34,3.45};
    int n;
    int i;
    int j;
    int k;
    FILE *ptr;

    ptr=fopen("Matrica.dat","r");

    fscanf(ptr,"%d",&n);

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            fscanf(ptr,"%f",&m[i][j]);
        }
        fscanf(ptr,"%f",&m[i][n]);
    }
    fclose(ptr);

    printf("Crout method\n\nSystem matrix\t\t\t\t\t\tVector\n\n");

     for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%f\t",m[i][j]);
        }
        printf("\t%f\n",m[i][n]);
    }

    for (j=0;j<n;j++)
    {
        for (i=0;i<=j;i++)
        {
            for (k=0;k<=(i-1);k++)
                m[i][j]=m[i][j]-m[i][k]*m[k][j];
        }
        for (i=j+1;i<n;i++)
        {
            for (k=0;k<=(j-1);k++)
                m[i][j]=m[i][j]-m[i][k]*m[k][j];
            m[i][j]=m[i][j]/m[j][j];
        }
    }

    for (i=0;i<n;i++)
    {
        y[i]=m[i][n];
        for (j=0;j<i;j++)
            y[i]=y[i]-m[i][j]*y[j];
    }

    for (i=n-1;i>=0;i--)
    {
        x[i]=y[i];
        for (j=i+1;j<n;j++)
            x[i]=x[i]-m[i][j]*x[j];
        x[i]=x[i]/m[i][i];
    }

    printf("\n\nResult:\tMathematica:\n");
    for (i=0;i<n;i++)
        printf("%f\t%f\n",x[i],mathematica[i]);

    return 0;
}
