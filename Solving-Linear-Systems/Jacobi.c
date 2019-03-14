#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char dati[]="C:/Matrica.dat";
    float e;
    float matrica[5][5];
    float atrisinajums0[3];
    float atrisinajums1[3];
    float atrisinajums2[3];
    float mathematica[3]={1.2299998,2.340000,3.450000};
    int n;
    int i;
    int j;
    int k;
    int s;
    FILE *ptr;

    printf("Choose precision e=");
    scanf("%f",&e);

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

    printf("Jacobi method\n\nSystem matrix\t\t\t\t\t\tVector\n\n");

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%f\t",matrica[i][j]);
        }
        printf("\t%f\n",matrica[i][n]);
    }

    for (i=0;i<n;i++)
        atrisinajums1[i]=0;

    s=0;
    do
    {
        s++;
        k=1;
        while (k<=2)
        {
            for (i=0;i<n;i++)
            {
                atrisinajums2[i]=matrica[i][n];
                for (j=0;j<n;j++)
                {
                    if (i!=j)
                        atrisinajums2[i]=atrisinajums2[i]-matrica[i][j]*atrisinajums1[j];
                }
                atrisinajums2[i]=atrisinajums2[i]/matrica[i][i];
            }

            for (i=0;i<n;i++)
                atrisinajums0[i]=atrisinajums1[i];

            for (i=0;i<n;i++)
                atrisinajums1[i]=atrisinajums2[i];
            k++;
        }
    }
    while (fabs(atrisinajums2[0]-atrisinajums0[0])>e && fabs(atrisinajums2[1]-atrisinajums0[1])>e && fabs(atrisinajums2[2]-atrisinajums0[2])>e);

    printf("\n\nResult:\tMathematica:\n");
    for (i=0;i<n;i++)
        printf("%f\t%f\n",atrisinajums2[i],mathematica[i]);

    printf("\nNo of steps: %d\n",2*s);

    return 0;
}
