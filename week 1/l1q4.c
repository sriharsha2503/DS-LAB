#include<stdio.h>
int main()
{
    int a[10][10];
    int b[10][10];

	int n,m,p,q,i,j;
 
    printf("enter order of matrix a /n");
    scanf(" %d %d",&m,&n);

    printf("enter elements /n");
    for(i=0;i<m;i++)
    {
       for(j=0;j<n;j++)
       {
    	scanf("%d",&a[i][j]);
        }
    }

    printf("enter columns of matrix b /n");
    scanf(" %d",&p);

    printf("enter elements /n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<p;j++)
       {
        scanf("%d",&b[i][j]);
        }
    }
    
    multiply(a,b,m,n,p);
    }

void multiply(int a[10][10],int b[10][10],int m,int n,int p)
{
int mu[10][10];
int i,j,k; 
    for(i=0;i<m;i++)
    {
       for(j=0;j<n;j++)
       {
         mu[i][j]=0;
         {
         
       
        }
    }

    
    
