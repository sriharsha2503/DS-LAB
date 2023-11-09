#include <stdio.h>

#include <stdlib.h>


#define MAX_SIZE 100


struct TwoStacks {

    int top1;

    int top2;

    int arr[MAX_SIZE];

};

struct TwoStacks* initializeTwoStacks() {

    struct TwoStacks* ts = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));

    ts->top1 = -1;

    ts->top2 = MAX_SIZE;

    return ts;

}

void push1(struct TwoStacks* ts, int data) {

    if (ts->top1 < ts->top2 - 1) {

        ts->arr[++ts->top1] = data;

    } else {

        printf("Stack Overflow\n");

    }

}

void push2(struct TwoStacks* ts, int data) {

    if (ts->top1 < ts->top2 - 1) {

        ts->arr[--ts->top2] = data;

    } else {

        printf("Stack Overflow\n");

    }

}

int pop1(struct TwoStacks* ts) {

    if (ts->top1 >= 0) {

        return ts->arr[ts->top1--];

    } else {

        printf("Stack 1 is empty\n");

        return -1;

    }

}

int pop2(struct TwoStacks* ts) {

    if (ts->top2 < MAX_SIZE) {

        return ts->arr[ts->top2++];

    } else {

        printf("Stack 2 is empty\n");

        return -1; // Return -1 for empty stack

    }

}


int main() {

    struct TwoStacks* ts = initializeTwoStacks();


    push1(ts, 1);

    push2(ts, 2);

    push1(ts, 3);


    printf("Popped element from stack 1: %d\n", pop1(ts));

    printf("Popped element from stack 2: %d\n", pop2(ts));


    return 0;

}


	
