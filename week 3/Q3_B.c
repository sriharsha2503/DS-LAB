#include<stdio.h>
int *fxn(){
	static int a=10;
	return (&a);
   }
int main(){
	int *p;
	p=fxn();
	printf("%p \n",p);
	printf("%d \n",*p);
	return 0;
}
