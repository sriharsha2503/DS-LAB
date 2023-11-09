#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
struct Stack {
    char data[MAX_SIZE];
    int top;
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
void push(struct Stack *stack, char item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->top++;
        stack->data[stack->top] = item;
    }
}
char pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        char item = stack->data[stack->top];
        stack->top--;
        return item;
    }
    return '\0';
}
int isPalindrome(const char *str) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            push(&stack, c);
        }
    }

    for (int i = 0; i < length; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (c != pop(&stack)) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
