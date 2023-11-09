#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

// Structure to represent a circular queue
struct CircularQueue {
    char** elements;
    int front;
    int rear;
    int size;
};

// Function to create a circular queue
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->elements = (char**)malloc(MAX_SIZE * sizeof(char*));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}


// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->size == 0;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return queue->size == MAX_SIZE;
}


// Function to insert an element into the circular queue
void insertcq(struct CircularQueue* queue, char* element) {
    if (isFull(queue)) {
        printf("Error: Circular queue is full!\n");
        return;
    }

    char* newElement = (char*)malloc((strlen(element) + 1) * sizeof(char));
    strcpy(newElement, element);

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->elements[queue->rear] = newElement;
    queue->size++;
}

// Function to delete an element from the circular queue
void deletecq(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Circular queue is empty!\n");
        return;
    }

    free(queue->elements[queue->front]);
    queue->elements[queue->front] = NULL;

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    queue->size--;
}

// Function to display the circular queue
void displaycq(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty!\n");
        return;
    }

    printf("Circular queue:\n");
    int i = queue->front;
    do {
        printf("%s\n", queue->elements[i]);
        i = (i + 1) % MAX_SIZE;//kiki
    } while (i != (queue->rear + 1) % MAX_SIZE);
}

int main() {
    struct CircularQueue* queue = createCircularQueue();

    insertcq(queue, "Apple");
    insertcq(queue, "Banana");
    insertcq(queue, "Cherry");

    displaycq(queue);

    deletecq(queue);

    displaycq(queue);

    insertcq(queue, "Date");
    insertcq(queue, "Elderberry");

    displaycq;}
