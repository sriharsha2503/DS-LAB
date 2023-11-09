#incude<stdio.h>

void triplets(int a[],int n)
{
int flag=0;
int i,j,k;
for (i=0;i<n-2;i++){
 for(j=i+1;j<n-1;j++){
    for(k=i+2;k<n;k++){
   
   if(a[i]+a[j]+a[k]==0)
   {
   printf("%d %d %d",a[i],a[j],a[k]);
   flag=1;
   }
  }
  }
  }
  
  if(flag==0)
  {
  printf("no triplets");
  }
  
 }
 
 int main()
 {
  int a[100],n;
  
  printf("enter number of elements");
  scanf("%d",&n);
  
  printf("enter elements");
   for(i=0;i<n;i++)
   {
   scanf("%d",a[i]);
   }
   triplets(a,n);
   return 0;
   }
   
