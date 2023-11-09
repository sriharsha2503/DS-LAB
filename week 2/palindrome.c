//To check whether a given String is Palindrome or not, using Recursion


#include<stdio.h>
#include<string.h>
int palindrome(char str[],int i,int n)
{
	if(i==n)
	{return 1;}

	if(str[i]==!str[n])
	{ return 0;}

   return palindrome(str,i+1,n-1)
}

int main()
{
	
	char str[100];
	printf("enter string");
	scanf("%s",str);
	int x=strlen(str);
    copystring(str,0,x-1);
    if (palindrome==1) 
        {printf("%s is a palindrome.\n", str);}
     else 
        {printf("%s is not a palindrome.\n", str);}
    

    return 0;
}