#include <stdio.h>
#include <stdlib.h>
#include <mgl/mgl_c.h>
#include <math.h>
int main()
{
HMGL gr = mgl_create_graph_zb(600,400);

float x;
float a1[7];
float a2[7];
int i;
int j;
float dati[7][2]={{0,0.05},{1,1.3},{2,2.15},{3,3.01},{4,3.95},{5,4.87},{6,6.0}};
int N=7;
HMDT datix,datiy,liknex,likney;
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

a1[0]=dati[0][1];
a2[0]=dati[0][1];
a1[1]=dati[1][1];
a1[2]=dati[2][1];
a1[3]=dati[3][1];
a1[4]=dati[4][1];
a1[5]=dati[5][1];
a1[6]=dati[6][1];

for (j=1;j<N;j++)
{
    for (i=j;i<N;i++)
    {
            a2[i]=(a1[i]-a1[j-1])/(dati[i][0]-dati[j-1][0]);
    }
    for (i=j;i<N;i++)
        a1[i]=a2[i];
}

printf("Newton polynomial\n\n");
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
mgl_data_set_value(likney, a2[0]+(x-dati[0][0])*(a2[1]+(x-dati[1][0])*(a2[2]+(x-dati[2][0])*(a2[3]+(x-dati[3][0])*(a2[4]+(x-dati[4][0])*(a2[5]+(x-dati[5][0])*a2[6]))))), i, 0, 0); //pielasa tikpat y vertibas
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
