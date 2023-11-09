#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
struct stack{
	int top;
	int items[MAX-SIZE];
};

void initialize(struct stack *stack){
	stack->top=-1;
}
int isempty(struct stack *stack){
return(stack->top==-1);
}
void push(struct stack *stack,int value){
	if(stack->top==MAX_SIZE -1)
	printf("stack overflow");
	exit(1);

}

int pop(struct stack *stack){
	
	
}