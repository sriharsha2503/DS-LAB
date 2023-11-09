#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
struct stack{
	int top;
	char items[MAX_SIZE];
};


void initialize(struct stack *stack){
	stack->top=-1;
}

int isempty(struct stack *stack){
return(stack->top==-1);}

void push(struct stack *stack,char value){
	if(stack->top==MAX_SIZE -1){
	printf("stack overflow");
	exit(1);}
	stack->items[++stack->top]=value;
}

char pop(struct stack*stack){
if(isempty(stack)){
	printf("stack overflow");
	exit(1);
}
return stack->items[stack->top--];
}

int isoperator(char c){
 return (c =='+' || c =='-' || c =='*' || c =='/' );

}

int precedence(char operator){
	if(operator =='+' ||operator =='-'){
		return 1;}
    else if(operator =='*' ||operator =='/'){
    	return 2;
    }
    else
    	return 0;
}

void infixtopostfix(char *infix,char *postfix){
	struct stack stack;
	initialize(&stack);

	int infixlen=strlen(infix);
	int postfixindex=0;

	for(int i=infixlen-1;i>=0;i--){
		char currentchar=infix[1];

		if(isoperator(currentchar)){
         while(!isempty(&stack)&& precedence(stack.items[stack.top]) > precedence(currentchar)){
        postfix[postfixindex++]=pop(&stack);
         }
         pop(&stack);
         }
         else if(currentchar ==')'){
         	push(&stack,currentchar);
         }
         else if(currentchar =='('){
          while(!isempty(&stack) && stack.items[stack.top]!=')'){
          	postfix[postfixindex++]=pop(&stack);
          }
      }
         else{
         postfix[postfixindex++]=currentchar;
         }
         }
         


	while(!isempty(&stack)){
			postfix[postfixindex++]=pop(&stack);
	}
		postfix[postfixindex]='\0';
		int postfixlen=strlen(postfix);
		for(int i=0;i< postfixlen/2;i++){
			char temp=postfix[i];
			postfix[i]=postfix[postfixlen-1-i];
			postfix[postfixlen-i-1]=temp;
		}
	
		}
	int main()
	{
		char infix[MAX_SIZE];
		char postfix[MAX_SIZE];

		printf("Enter infix expression \n");
		scanf("%s",infix);

		infixtopostfix(infix,postfix);
		printf("%s \n",postfix);

		return 0;
	}


	