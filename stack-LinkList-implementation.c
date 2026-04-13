#include <stdio.h>
#include <stdlib.h>

// -------------------- NODE STRUCTURE --------------------
// Each node contains data and pointer to next node
struct Node {
    int data;              // value stored in node
    struct Node* next;     // pointer to next node
};

// -------------------- TOP POINTER --------------------
// This will always point to the top of stack
struct Node* top = NULL;


// -------------------- PUSH FUNCTION --------------------
void push(int value) {

    // Step 1: Create a new node dynamically
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Step 2: Check if memory allocation failed
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        
        return;
    }

    // Step 3: Store the value in node
    newNode->data = value;

    // Step 4: Link new node to previous top
    newNode->next = top;

    // Step 5: Update top pointer to new node
    top = newNode;

    printf("%d pushed into stack\n", value);
}


// -------------------- POP FUNCTION --------------------
void pop() {

    // Step 1: Check if stack is empty
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    // Step 2: Store current top node in temp
    struct Node* temp = top;

    // Step 3: Print the value being removed
    printf("%d popped from stack\n", top->data);

    // Step 4: Move top to next node
    top = top->next;

    // Step 5: Free memory of removed node
    free(temp);
}


// -------------------- PEEK FUNCTION --------------------
void peek() {

    // Check if stack is empty
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        // Print top element without removing it
        printf("Top element is: %d\n", top->data);
    }
}


// -------------------- DISPLAY FUNCTION --------------------
void display() {

    // Check if stack is empty
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    // Temporary pointer for traversal
    struct Node* temp = top;

    printf("Stack elements:\n");

    // Traverse the linked list until NULL
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;   // move to next node
    }

    printf("NULL\n");
}


// -------------------- MAIN FUNCTION --------------------
int main() {
    int choice, value;

    // Infinite loop for menu-driven program
    while (1) {

        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user choice
        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}