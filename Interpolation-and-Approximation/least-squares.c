#include <stdio.h>
#include <stdlib.h>
#include <mgl/mgl_c.h>
#include <math.h>

int main()
{
HMGL gr = mgl_create_graph_zb(600,400); 

float x;
float a[3];
float matrica[3][4];
float sum;
int i;
int j;
int k;
int n=3;
float dati[7][2]={{0,0.05},{1,1.3},{2,2.15},{3,3.01},{4,3.95},{5,4.87},{6,6.0}};
int N=7; //N is the number of points
HMDT datix,datiy,liknex,likney; //define 4 data groups

datix = mgl_create_data_size(N,1,1); 
datiy = mgl_create_data_size(N,1,1); 
liknex = mgl_create_data_size(101,1,1); 
likney = mgl_create_data_size(101,1,1); 

mgl_set_axis_2d(gr,0.,0.,6.,6.); 
mgl_box(gr,1); 



for (i=0; i<N; i++) 
{
mgl_data_set_value(datix, i, i, 0, 0); 
mgl_data_set_value(datiy, dati[i][1], i, 0, 0); 
} 


mgl_plot_xy(gr,datix, datiy, "b#s "); 

matrica[0][0]=N-1;

sum=0;
for (i=0;i<=6;i++)
    sum=sum+dati[i][0];
matrica[0][1]=matrica[1][0]=sum;

sum=0;
for (i=0;i<=6;i++)
    sum=sum+dati[i][0]*dati[i][0];
matrica[0][1]=matrica[1][1]=matrica[2][0]=sum;

sum=0;
for (i=0;i<=6;i++)
    sum=sum+dati[i][0]*dati[i][0]*dati[i][0];
matrica[1][2]=matrica[2][1]=sum;

sum=0;
for (i=0;i<=6;i++)
    sum=sum+dati[i][0]*dati[i][0]*dati[i][0]*dati[i][0];
matrica[2][2]=sum;

sum=0;
for (i=0;i<=6;i++)
    sum=sum+dati[i][1];
matrica[0][3]=sum;

sum=0;
for (i=0;i<=6;i++)
    sum=sum+dati[i][1]*dati[i][0];
matrica[1][3]=sum;

sum=0;
for (i=0;i<=6;i++)
    sum=sum+dati[i][1]*dati[i][0]*dati[i][0];
matrica[2][3]=sum;

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

    a[n-1]=matrica[n-1][n];

    for (i=n-2;i>=0;i=i-1)
    {
        for (j=i+1;j<=(n-1);j++)
            matrica[i][n]=matrica[i][n]-a[j]*matrica[i][j];
        a[i]=matrica[i][n];
    }

printf("Approximation using least squares\n\n");
printf("x\t");
for (i=0;i<7;i++)
    printf("%3.2f\t",dati[i][0]);
printf("\ny\t");
for (i=0;i<7;i++)
    printf("%3.2f\t",dati[i][1]);
printf("\n\n");

for (i=0; i<101; i++) 
{ 
x = i*0.06; 
mgl_data_set_value(liknex, x, i, 0, 0); 
mgl_data_set_value(likney, a[0] + a[1]*x + a[2]*x*x, i, 0, 0); 
}

mgl_plot_xy(gr,liknex, likney, "r-"); 

mgl_delete_data(datix); 
mgl_delete_data(datiy);
mgl_delete_data(liknex); 
mgl_delete_data(likney); 

mgl_write_png (gr, "grafiks.png","001"); 
system("grafiks.png"); 
mgl_delete_graph(gr); 

return 0;
}

