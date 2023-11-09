#include<stdio.h>

void reverse (int *p,int arr_size)
{
	int *p1=p;
	int *p2=p + arr_size -1;
    while(p1<p2){
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
    p1++;
    p2--; 
      }
    }

 int main(){
 int arr[30],n,i;
 printf("enter the number of elements :");
 scanf("%d",&n);
 printf("enter elements \n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&arr[i]);
 }    
 reverse(arr,n);
 printf("array after reversing is : /n");
 for(i=0;i<n;i++){
 printf("%d \t",arr[i]);
 }

return 0;


    }