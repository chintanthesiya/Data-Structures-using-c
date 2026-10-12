#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* start, int data) {
    struct Node* newNode = createNode(data);
    if (start == NULL) {
        newNode->next = newNode;
        printf("Success: Inserted %d at beginning.\n", data);
        return newNode;
    }
    struct Node* temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = start;
    printf("Success: Inserted %d at beginning.\n", data);
    return newNode;
}

struct Node* insertAtEnd(struct Node* start, int data) {
    struct Node* newNode = createNode(data);
    if (start == NULL) {
        newNode->next = newNode;
        printf("Success: Inserted %d at end.\n", data);
        return newNode;
    }
    struct Node* temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = start;
    printf("Success: Inserted %d at end.\n", data);
    return start;
}

struct Node* deleteFromBeginning(struct Node* start) {
    if (start == NULL) {
        printf("Error: List is already empty.\n");
        return NULL;
    }
    if (start->next == start) {
        printf("Success: Deleted %d.\n", start->data);
        free(start);
        return NULL;
    }
    struct Node* temp = start;
    while (temp->next
