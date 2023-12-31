#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* unionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL) {
        result = insert(result, list1->data);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        result = insert(result, list2->data);
        list2 = list2->next;
    }
    return result;
}

struct Node* intersectionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL) {
        struct Node* temp = list2;
        while (temp != NULL) {
            if (list1->data == temp->data) {
                result = insert(result, list1->data);
                break;
            }
            temp = temp->next;
        }
        list1 = list1->next;
    }
    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int num1, num2;

    // Accept user input for the first list
    printf("Enter elements for List 1 (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num1);
        if (num1 == -1) {
            break;
        }
        list1 = insert(list1, num1);
    }

    // Accept user input for the second list
    printf("Enter elements for List 2 (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num2);
        if (num2 == -1) {
            break;
        }
        list2 = insert(list2, num2);
    }

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node* unionResult = unionLists(list1, list2);
    printf("UNION: ");
    display(unionResult);

    struct Node* intersectionResult = intersectionLists(list1, list2);
    printf("INTERSECTION: ");
    display(intersectionResult);

    return 0;
}