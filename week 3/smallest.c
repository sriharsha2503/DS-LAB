#include<stdio.h>

int smallest(int a[30],int n)
{
	int *small=&a[0];
	int i;
	for(i=0;i<n;i++)
	{
      (if *(a+i)< *small){
      *small=*(a+i);}

    }
    return *small;
}

int main()
{
 printf("enter number of elements");
 int arr[30],n,i,sm;
 scanf("%d",&n);
 printf("enter elements :");

 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
  sm=smallest(arr,n);
  printf("the smallest element is %d",sm);

}