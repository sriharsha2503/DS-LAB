#include<stdio.h>
void swap(int *a,int *b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
int main()
{
  int a=10,b=20;
  printf("values before swap \n");
  printf("%p %p \n",&a,&b);

  swap(&a,&b);
  printf("values after swap \n");
  printf("%p %p \n",&a,&b);
 
 return 0;
}