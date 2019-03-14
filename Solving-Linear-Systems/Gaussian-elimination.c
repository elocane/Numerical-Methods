#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char dati[]="C:/Matrica.dat";
    float matrica[5][5];
    float atrisinajums[3];
    float mathematica[3]={1.2299998,2.340000,3.450000};
    int n;
    int i;
    int j;
    int k;
    FILE *ptr;

    ptr=fopen(dati,"r");

    fscanf(ptr,"%d",&n);

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            fscanf(ptr,"%f",&matrica[i][j]);
        }
        fscanf(ptr,"%f",&matrica[i][n]);
    }
    fclose(ptr);

    printf("Gaussian elimination\n\nSystem matrix\t\t\t\t\t\tVector\n\n");

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%f\t",matrica[i][j]);
        }
        printf("\t%f\n",matrica[i][n]);
    }

    for (i=0;i<n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            matrica[i][j]=matrica[i][j]/matrica[i][i];
        }

        matrica[i][i]=1.0;

        for (k=i+1;k<n;k++)
        {
            for(j=i+1;j<=n;j++)
            {
                matrica[k][j]=matrica[k][j]-matrica[i][j]*matrica[k][i];
            }
            matrica[k][i]=0.0;
        }
    }

    atrisinajums[n-1]=matrica[n-1][n];

    for (i=n-2;i>=0;i=i-1)
    {
        for (j=i+1;j<=(n-1);j++)
            matrica[i][n]=matrica[i][n]-atrisinajums[j]*matrica[i][j];
        atrisinajums[i]=matrica[i][n];
    }

    printf("\n\nResult:\tMathematica:\n");
    for (i=0;i<n;i++)
        printf("%f\t%f\n",atrisinajums[i],mathematica[i]);

    return 0;
}
