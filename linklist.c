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

struct Node* insertAtBeginning(struct Node* start, int new_data) {
    struct Node* newNode = createNode(new_data);
    newNode->next = start;
    printf("Success: Inserted %d at beginning.\n", new_data);
    return newNode; 
}

struct Node* insertAtEnd(struct Node* start, int new_data) {
    struct Node* newNode = createNode(new_data);
    if (start == NULL) {
        printf("Success: Inserted %d at end.\n", new_data);
        return newNode;
    }
    struct Node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Success: Inserted %d at end.\n", new_data);
    return start;
}

struct Node* insertAfterValue(struct Node* start, int target_value, int new_data) {
    struct Node* temp = start;
    
    while (temp != NULL && temp->data != target_value) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Error: Value %d not found in the list.\n", target_value);
        return start;
    }
    
    struct Node* newNode = createNode(new_data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Success: Inserted %d after %d.\n", new_data, target_value);
    return start;
}

struct Node* deleteFromBeginning(struct Node* start) {
    if (start == NULL) {
        printf("Error: List is already empty.\n");
        return NULL;
    }
    struct Node* temp = start;
    start = start->next;
    printf("Success: Deleted %d from beginning.\n", temp->data);
    free(temp);
    return start;
}

struct Node* deleteFromEnd(struct Node* start) {
    if (start == NULL) {
        printf("Error: List is already empty.\n");
        return NULL;
    }
    if (start->next == NULL) {
        printf("Success: Deleted %d from end.\n", start->data);
        free(start);
        return NULL;
    }
    struct Node* temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Success: Deleted %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return start;
}

struct Node* deleteByValue(struct Node* start, int val) {
    struct Node *temp = start, *prev = NULL;

    if (temp != NULL && temp->data == val) {
        start = temp->next;
        printf("Success: Deleted %d.\n", val);
        free(temp);
        return start;
    }

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: Value %d not found in list.\n", val);
        return start;
    }

    prev->next = temp->next;
    printf("Success: Deleted %d.\n", val);
    free(temp);
    return start;
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Current List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* start = NULL; 
    int choice, data, target;

    while (1) {
        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Value\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete a Specific Value\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("======================================\n");
        printf("Enter your choice (1-8): ");
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
                printf("Enter the existing value you want to insert after: ");
                scanf("%d", &target);
                printf("Enter the new number to insert: ");
                scanf("%d", &data);
                start = insertAfterValue(start, target, data);
                break;
                
            case 4:
                start = deleteFromBeginning(start);
                break;
                
            case 5:
                start = deleteFromEnd(start);
                break;
                
            case 6:
                printf("Enter the number you want to delete: ");
                scanf("%d", &target);
                start = deleteByValue(start, target);
                break;
                
            case 7:
                displayList(start);
                break;
                
            case 8:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    }
    
    return 0;
}
