#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int* array;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->array = (int*)malloc(size * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    if ((queue->front == 0 && queue->rear == queue->size - 1) ||
        (queue->front == queue->rear + 1))
        return 1;
    else
        return 0;
}

int isEmpty(Queue* queue) {
    if (queue->front == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    if (queue->front == -1)
        queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->size;
    queue->array[queue->rear] = data;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int data = queue->array[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->size;

    return data;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Queue elements: ");
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->size;
    }
    printf("%d\n", queue->array[i]);
}

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    Queue* queue1 = createQueue(N / 2);
    Queue* queue2 = createQueue(N - N / 2);

    int choice, data;
    while (1) {
        printf("\n---- Menu ----\n");
        printf("1. Enqueue to Queue 1\n");
        printf("2. Enqueue to Queue 2\n");
        printf("3. Dequeue from Queue 1\n");
        printf("4. Dequeue from Queue 2\n");
        printf("5. Display Queue 1\n");
        printf("6. Display Queue 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(queue1, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(queue2, data);
                break;
            case 3:
                data = dequeue(queue1);
                if (data != -1)
                    printf("Dequeued element from Queue 1: %d\n", data);
                break;
            case 4:
                data = dequeue(queue2);
                if (data != -1)
                    printf("Dequeued element from Queue 2: %d\n", data);
                break;
            case 5:
                display(queue1);
                break;
            case 6:
                display(queue2);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}