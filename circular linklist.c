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
    while (temp->next != start) {
        temp = temp->next;
    }
    struct Node* toDelete = start;
    temp->next = start->next;
    start = start->next;
    printf("Success: Deleted %d from beginning.\n", toDelete->data);
    free(toDelete);
    return start;
}

struct Node* deleteFromEnd(struct Node* start) {
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
    struct Node* prev = NULL;
    while (temp->next != start) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = start;
    printf("Success: Deleted %d from end.\n", temp->data);
    free(temp);
    return start;
}

void displayList(struct Node* start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = start;
    printf("Current Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("(back to start: %d)\n", start->data);
}

int main() {
    struct Node* start = NULL;
    int choice, data;

    while (1) {
        printf("\n========== CIRCULAR LINKED LIST ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &data);
                start = insertAtBeginning(start, data);
                break;
            case 2:
                printf("Enter number to insert: ");
                scanf("%d", &data);
                start = insertAtEnd(start, data);
                break;
            case 3:
                start = deleteFromBeginning(start);
                break;
            case 4:
                start = deleteFromEnd(start);
                break;
            case 5:
                displayList(start);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}
