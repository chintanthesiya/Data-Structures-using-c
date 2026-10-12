#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Error: Stack Overflow! Cannot push %d. Stack is full.\n", val);
        return;
    }
    top++;
    stack[top] = val;
    printf("Success: Pushed %d onto the stack.\n", val);
}

void pop() {
    if (top == -1) {
        printf("Error: Stack Underflow! Stack is already empty.\n");
        return;
    }
    printf("Success: Popped %d from the stack.\n", stack[top]);
    top--;
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current Stack (Top to Bottom):\n");
    int i=0;
    for(i = top; i >= 0; i--) {
        printf("| %4d |\n", stack[i]);
    }
    printf("--------\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n========== STACK MENU ==========\n");
        printf("1. Push (Insert value)\n");
        printf("2. Pop (Delete value)\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("================================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to push: ");
                scanf("%d", &val);
                push(val);
                break;
                
            case 2:
                pop();
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
