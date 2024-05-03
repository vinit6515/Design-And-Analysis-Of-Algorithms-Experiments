#include <stdio.h>
void naive_multiplication(int a[2][2],int b[2][2])
{
int c[2][2],i,j,k;
for (int i = 0; i <2 ; i++)
{
for (int j = 0; j <2; j++)
{
c[i][j] = 0;
for (int k = 0; k <2; k++)
{
c[i][j] += a[i][k]*b[k][j];
}
}
}for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("%d ",c[i][j]);
}
printf("\n");
}
}
void strassens(int a[2][2],int b[2][2])
{
int p1,p2,p3,p4,p5,p6,p7,c00,c01,c10,c11;
p1=a[0][0]*(b[0][1]-b[1][1]);
p2=b[1][1]*(a[0][0]+a[0][1]);
p3=b[0][0]*(a[1][0]+a[1][1]);
p4=a[1][1]*(b[1][0]-b[0][0]);
p5=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
p6=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
p7=(a[0][0]-a[1][0])*(b[0][0]+b[0][1]);
c00=p4+p5+p6-p2;
c01=p1+p2;
c10=p3+p4;
c11=p1-p3+p5-p7;
printf("\nBy Strassesns: \n");
printf("%d %d \n%d %d",c00,c01,c10,c11);
}
void main(){
printf("Vinit Shah C3-2 C183 60004220097\n");
int i,j,k,a[2][2],b[2][2];
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("Enter an element for Matrix A: ");
scanf("%d",&a[i][j]);
}
}
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("Enter an element for Matrix B: ");
scanf("%d",&b[i][j]);
}
}
naive_multiplication(a,b);
strassens(a,b);
}
