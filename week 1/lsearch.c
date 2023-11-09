#include<stdio.h>
int main()
{
	int i,pos,x,n;
	int flag=0;
	int arr[100];
	printf("number of elements");
	scanf("%d",&x);

	printf("enter element to be searched /n");
	scanf("%d",&n);
    
    printf("enter the elements");

    for(i=0;i<x;i++)
    {
      scanf("%d",&arr[i]);
    }

    for(i=0;i<x;i++)
    {
     if(n==arr[i])
     {
      pos=i+1;
      break;
     }
  

    printf("the position is %d",pos);

}