#include<stdio.h>
int main()
{
	int mat[10][10];
	int n,m,j, i;
    int count=0;
    printf("enter order of matrix /n");
    scanf(" %d %d",&m,&n);

    printf("enter elements /n");
    for(i=0;i<m;i++)
    {
       for(j=0;j<n;j++)
       {
        scanf("%d",&mat[i][j]);
        }
    }

    if(mat[i][j]==0)
    {
    count++;
    }
    
    if(count>((m*n)/2))
    {
    printf("The matrix is a sparse matrix");
    }
    return 0;
    }
