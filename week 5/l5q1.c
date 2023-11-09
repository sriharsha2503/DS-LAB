#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack {
    char data[MAX_SIZE];
    int top;
};
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push.\n");
    } else {
        stack->top++;
        stack->data[stack->top] = item;
        printf("Pushed %c onto the stack.\n", item);
    }
}
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
        return '\0';
    } else {
        char poppedItem = stack->data[stack->top];
        stack->top--;
        return poppedItem;
    }
}
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%c\n", stack->data[i]);
        }
    }
}

int main() {
    struct Stack stack;
    stack.top = -1;

    int choice;
    char item;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to push: ");
                scanf(" %c", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != '\0') {
                    printf("Popped %c from the stack.\n", item);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}
