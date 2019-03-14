#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void vec_copy (int numb, float *src, float *trg)
{
    int i;
    for (i=0;i<numb;i++)
        *(trg+i)=*(src+i);
}

float vec_vec_scal (int numb, float *vec1, float *vec2)
{
    int i;
    float sum=0;
    for (i=0;i<numb;i++)
        sum=sum+(*(vec1+i))*(*(vec2+i));
    return sum;
}

void matr_vec_scal (int numb, float *matr, float *vec, float *vec_rez)
{
    int i;
    int j;
    float sum;
    for (i=0;i<numb;i++)
    {
        sum=0;
        for (j=0;j<numb;j++)
            sum=sum+*(matr+numb*i+j)*(*(vec+j));
        *(vec_rez+i)=sum;
    }
}

void vec_plus_a_vec (int numb, float *vec1, float *vec2, float mlt, float *rez)
{
    int i;
    for (i=0;i<numb;i++)
        *(rez+i)=*(vec1+i)+mlt*(*(vec2+i));
}

void fill_vec (int numb, float *vec1, float value)
{
    int i;
    for (i=0;i<numb;i++)
        *(vec1+i)=value;
}

float max_vec_comp(int numb, float *vec)
{
    int i;
    float max=*(vec);
    for (i=1;i<numb;i++)
    {
        if (fabs(*(vec+i))>fabs(max))
            max=*(vec+i);
    }
    return fabs(max);
}

void matr_matr(int numb, float *m1, float *m2, float *trg)
{
    int i;
    int j;
    int k;
    for (i=0;i<numb;i++)
    {
        for (j=0;j<numb;j++)
        {
            *(trg+i*numb+j)=0;
            for (k=0;k<numb;k++)
                *(trg+i*numb+j)+=(*(m1+i*numb+k))*(*(m2+k*numb+j));
        }
    }
}

int main()
{
    int i;
    int j;
    int k;
    int n;
    float e;
    float a;
    float b;
    float ro1;
    float ro2;
    char buff[10];
    float *m;
    float *m1;
    float *inv;
    float *x;
    float *r;
    float *p;
    float *q;
    float *d;
    FILE *fl=fopen("cg01.dat","r");

    fscanf(fl,"%d",&n);
    fgets(buff,9,fl);

    m= (float *) calloc (n*n+n, sizeof(float));
    for (i=0;i<n*n+n;i++)
        fscanf(fl,"%e",(m+i));

    fclose(fl);

    m1=(float *) calloc(n*n,sizeof(float));
    d=(float *) calloc(n*n,sizeof(float));
    inv=(float *) calloc(n*n,sizeof(float));
    x=(float *) calloc(n,sizeof(float));
    r=(float *) calloc(n,sizeof(float));
    p=(float *) calloc(n,sizeof(float));
    q=(float *) calloc(n,sizeof(float));
    vec_copy(n*n,m,m1);

    //Finding the inverse matrix
    //Creating the unit matrix
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            if (i==j)
                *(inv+n*i+j)=1.0;
            else
                *(inv+n*i+j)=0.0;
        }

    //Finding the inverse matrix -- forward step
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
            *(m1+i*n+j)=(*(m1+i*n+j))/(*(m1+i*n+i));
        for (j=0;j<n;j++)
            *(inv+i*n+j)=(*(inv+i*n+j))/(*(m1+i*n+i));
        *(m1+i*n+i)=1.0;

        for (k=i+1;k<n;k++)
        {
            for (j=i+1;j<n;j++)
                *(m1+k*n+j)=*(m1+k*n+j)-*(m1+k*n+i)*(*(m1+i*n+j));
            for (j=0;j<n;j++)
                *(inv+k*n+j)=(*(inv+k*n+j))-(*(m1+k*n+i))*(*(inv+i*n+j));
            *(m1+k*n+i)=0;
        }
    }

    //Finding inverse matrix -- backward step
    for (i=n;i>0;i--)
    {
        for (j=0;j<=i-1;j++)
        {
            for (k=0;k<n;k++)
                *(inv+j*n+k)=(*(inv+j*n+k))-(*(inv+i*n+k))*(*(m1+j*n+i));
        }
    }

    /*Writing to file
    fl=fopen("InverseMatrix.dat","w");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            fprintf(fl,"%f   ",*(inv+i*n+j));
        fprintf(fl,"\n");
    }
    fclose(fl);*/

    //Writing to file
    fl=fopen("Rezultati.dat","w");
    fprintf(fl,"Inversa matrica\n\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            fprintf(fl,"%10.6f   ",*(inv+i*n+j));
        fprintf(fl,"\n");
    }
    fclose(fl);

    /*Checking AA^-1
    matr_matr(n,m,inv,d);
    fl=fopen("Parbaude.dat","w");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            fprintf(fl,"i=%d, j=%d, %f \n",i,j,*(d+i*n+j));
    }
    fclose(fl);*/

    //Writing to file
    matr_matr(n,m,inv,d);
    fl=fopen("Rezultati.dat","a");
    fprintf(fl,"\n\nParbaudes vienibas matrica\n\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            fprintf(fl,"%15.12f\t",*(d+i*n+j));
        fprintf(fl,"\n");
    }
    fclose(fl);


    //Printing the inverse matrix
    printf("Indeksi\tInversa matrica\tVienibas matrica parbaudei:\n");
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            printf("i=%d, j=%d\t%12.8f\t%15.12f\n",i,j,*(inv+i*n+j),*(d+i*n+j));

    //Conjugate gradient method
    printf("\n\nConjugate gradient method\nChoose precision e=");
    scanf("%f",&e);
    fill_vec(n,x,0);
    matr_vec_scal(n,m,x,r);
    vec_plus_a_vec(n,(m+n*n),r,-1,r);
    ro1=vec_vec_scal(n,r,r);
    vec_copy(n,r,p);
    matr_vec_scal(n,m,p,q);
    a=ro1/vec_vec_scal(n,p,q);
    vec_plus_a_vec(n,x,p,a,x);
    vec_plus_a_vec(n,r,q,-a,r);

    do
    {
        ro2=vec_vec_scal(n,r,r);
        b=ro2/ro1;
        vec_plus_a_vec(n,r,p,b,p);
        matr_vec_scal(n,m,p,q);
        a=ro2/vec_vec_scal(n,p,q);
        vec_plus_a_vec(n,x,p,a,x);
        vec_plus_a_vec(n,r,q,-a,r);
        ro1=ro2;
    }
    while (max_vec_comp(n,r)>e);

    
    matr_vec_scal(n,m,x,r);
    vec_plus_a_vec(n,r,(m+n*n),-1,r);

   
    printf("\nAtrisinajums\tNesaite\n\n");
    for (i=0;i<n;i++)
        printf("%12.8f\t%12.8f\n",*(x+i),*(r+i));


    
    fl=fopen("Rezultati.dat","a");
    fprintf(fl,"\n\nAtrisinajums\t  Nesaite\n\n");
    for (i=0;i<n;i++)
        fprintf(fl,"%12.8f\t%12.8f\n",*(x+i),*(r+i));

    printf("\n\nHola, que pasa?!");

    free((float *) m);
    free((float *) m1);
    free((float *) d);
    free((float *) r);
    free((float *) p);
    free((float *) q);
    free((float *) inv);
    free((float *) x);

    return 0;
}
