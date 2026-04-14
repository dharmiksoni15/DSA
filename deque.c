#include <stdio.h>

#define SIZE 5   // Maximum size of deque

int dq[SIZE];   // Array to store deque elements
int front = -1; // Front pointer (start of deque)
int rear = -1;  // Rear pointer (end of deque)

// Function to check if deque is full
int isFull() {
    // Condition for full deque (circular logic)
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Function to check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert element at rear
void insertRear(int value) {

    // Check overflow condition
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    // If deque is empty, initialize front and rear
    if (front == -1) {
        front = rear = 0;
    }
    // If rear is at last index, move to first (circular)
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    // Otherwise move rear forward
    else {
        rear++;
    }

    dq[rear] = value;  // Insert value at rear
    printf("Inserted at rear: %d\n", value);
}

// Function to insert element at front
void insertFront(int value) {

    // Check overflow condition
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    // If deque is empty
    if (front == -1) {
        front = rear = 0;
    }
    // If front is at first index, move to last (circular)
    else if (front == 0) {
        front = SIZE - 1;
    }
    // Otherwise move front backward
    else {
        front--;
    }

    dq[front] = value;  // Insert value at front
    printf("Inserted at front: %d\n", value);
}

// Function to delete element from front
void deleteFront() {

    // Check underflow condition
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted from front: %d\n", dq[front]);

    // If only one element was present
    if (front == rear) {
        front = rear = -1;
    }
    // If front is at last index, move to start
    else if (front == SIZE - 1) {
        front = 0;
    }
    // Otherwise move front forward
    else {
        front++;
    }
}

// Function to delete element from rear
void deleteRear() {

    // Check underflow condition
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted from rear: %d\n", dq[rear]);

    // If only one element was present
    if (front == rear) {
        front = rear = -1;
    }
    // If rear is at first index, move to last
    else if (rear == 0) {
        rear = SIZE - 1;
    }
    // Otherwise move rear backward
    else {
        rear--;
    }
}

// Function to display deque elements
void display() {

    // Check if deque is empty
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;  // Start from front

    printf("Deque elements: ");

    // Traverse circularly from front to rear
    while (1) {
        printf("%d ", dq[i]);

        if (i == rear)  // Stop when rear is reached
            break;

        i = (i + 1) % SIZE;  // Circular increment
    }

    printf("\n");
}

// Main function (menu-driven)
int main() {

    int choice, value;

    while (1) {

        // Display menu
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);   // Call insertFront
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);    // Call insertRear
                break;

            case 3:
                deleteFront();        // Call deleteFront
                break;

            case 4:
                deleteRear();         // Call deleteRear
                break;

            case 5:
                display();            // Show deque
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}