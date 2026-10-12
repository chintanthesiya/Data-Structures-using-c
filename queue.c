#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int queue[MAX];
int front = -1;
int rear = -1;


void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Error: Queue Overflow! Cannot insert %d. Queue is full.\n", val);
        return;
    }
    

    if (front == -1) {
        front = 0;
    }
    
    rear++;
    queue[rear] = val;
    printf("Success: Inserted %d into the queue.\n", val);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Error: Queue Underflow! Queue is already empty.\n");
        return;
    }
    
    printf("Success: Deleted %d from the queue.\n", queue[front]);
    front++;
    

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}


void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Current Queue: ");
    int i=0;
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n(Front is %d, Rear is %d)\n", queue[front], queue[rear]);
}


int main() {
    int choice, val;

    while (1) {
        printf("\n========== QUEUE MENU ==========\n");
        printf("1. Enqueue (Insert value)\n");
        printf("2. Dequeue (Delete value)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("================================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    
    return 0;
}
