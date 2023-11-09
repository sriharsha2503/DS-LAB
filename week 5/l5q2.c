#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 32

struct Stack {
    int data[MAX_SIZE];
    int top;
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
void push(struct Stack *stack, int item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->top++;
        stack->data[stack->top] = item;
    }
}
int pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        int item = stack->data[stack->top];
        stack->top--;
        return item;
    }
    return -1;
}
void decimalToBinary(int decimal) {
    struct Stack stack;
    initialize(&stack);

    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }

    printf("Binary representation: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal < 0) {
        printf("Please enter a positive decimal number.\n");
    } else {
        decimalToBinary(decimal);
    }

    return 0;
}
