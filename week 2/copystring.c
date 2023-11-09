#include<stdio.h>

void copystring(char str1[],char str2[],int i)
{
	str1[i]=str2[i];
	if(str2[i]==!0)
	{
      return ;

	}
	copystring(str1,str2,i+1);
}

int main()
{
	char str1[100],str2[100];
	printf("enter string to be copied" );
	scanf("%s",str2);
    copystring(str1,str2,0);
    printf("the string is %s", str1);
    return 0;
}