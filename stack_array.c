#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of stack

int stack[MAX];   // Array to store stack elements
int top = -1;     // Top pointer (-1 means stack is empty)


// -------------------- PUSH OPERATION --------------------
void push(int value) {

    // Check if stack is full
    if (top == MAX - 1) {
        printf("Stack Overflow \n");
        return;
    }

    // Move top one position up
    top++;

    // Insert value at new top position
    stack[top] = value;

    printf("%d pushed into stack ✅\n", value);
}


// -------------------- POP OPERATION --------------------
void pop() {

    // Check if stack is empty
    if (top == -1) {
        printf("Stack Underflow \n");
        return;
    }

    // Print the element which will be removed
    printf("%d popped from stack\n", stack[top]);

    // Move top down (remove element logically)
    top--;
}


// -------------------- PEEK OPERATION --------------------
void peek() {

    // Check if stack is empty
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    // Show the top element without removing it
    printf("Top element is: %d\n", stack[top]);
}


// -------------------- DISPLAY OPERATION --------------------
void display() {

    // Check if stack is empty
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");

    // Print elements from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}


// -------------------- MAIN FUNCTION --------------------
int main() {
    int choice, value;

    // Infinite loop for menu-driven program
    while (1) {

        // Display menu
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        // Take user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user input
        switch (choice) {

            case 1:
                // Take value from user for push
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                // Remove top element
                pop();
                break;

            case 3:
                // Show top element
                peek();
                break;

            case 4:
                // Display all elements
                display();
                break;

            case 5:
                // Exit program
                printf("Exiting...\n");
                exit(0);

            default:
                // Invalid choice handling
                printf("Invalid choice \n");
        }
    }
}