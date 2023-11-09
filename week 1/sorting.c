#include<stdio.h>
int main()
{
	int arr[10];
	int n, i,temp;
 
    printf("enter number of elements /n");
    scanf(" %d",&n);

    printf("enter elements /n");
    for(i=0;i<n;i++)
    {

    	scanf("%d",&arr[i]);
    }
    

    for(i=0;i<n;i++)
    {

    	if(arr[i]>arr[i+1])
    	{
    		temp=arr[i];
    		arr[i+1]=arr[i];
    		arr[i+1]=temp;
    	}

    }

    
    	printf( "the ascending order will be %d /n ",arr[i]);
    

    return 0;
}