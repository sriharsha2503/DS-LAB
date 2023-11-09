#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *data;
    int top;
};

void initialize(struct Stack *stack, int size) {
    stack->data = (int *)malloc(size * sizeof(int));
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int item) {
    stack->top++;
    stack->data[stack->top] = item;
}

int pop(struct Stack *stack) {
    int item = stack->data[stack->top];
    stack->top--;
    return item;
}

void deleteElements(int arr[], int n, int k) {
    struct Stack stack;
    initialize(&stack, n);

    for (int i = 0; i < n; i++) {
        while (!isEmpty(&stack) && k > 0 && arr[i] > stack.data[stack.top]) {
            pop(&stack);
            k--;
        }
        push(&stack, arr[i]);
    }

    while (k > 0) {
        pop(&stack);
        k--;
    }

    printf("Output: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");

    free(stack.data);
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int arr[n];

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Invalid k value.\n");
        return 1;
    }

    deleteElements(arr, n, k);

    return 0;
}

