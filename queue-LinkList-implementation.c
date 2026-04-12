#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;              // Stores the value
    struct Node* next;     // Pointer to next node
};

// Declare front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue function (Insert element at rear)
void enqueue(int value) {
    // Step 1: Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Step 2: Assign data and set next to NULL
    newNode->data = value;
    newNode->next = NULL;

    // Step 3: Check if queue is empty
    if (rear == NULL) {
        // First element: both front and rear point to new node
        front = rear = newNode;
        return;
    }

    // Step 4: Link new node at the end of queue
    rear->next = newNode;

    // Step 5: Move rear pointer to new node
    rear = newNode;
}

// Dequeue function (Delete element from front)
void dequeue() {
    // Step 1: Check if queue is empty
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    // Step 2: Store front node in temporary pointer
    struct Node* temp = front;

    // Step 3: Print the deleted value
    printf("Deleted: %d\n", temp->data);

    // Step 4: Move front to next node
    front = front->next;

    // Step 5: If queue becomes empty, update rear also
    if (front == NULL) {
        rear = NULL;
    }

    // Step 6: Free memory of deleted node
    free(temp);
}

// Display function (Print queue elements)
void display() {
    // Step 1: Create temporary pointer to traverse
    struct Node* temp = front;

    // Step 2: Check if queue is empty
    if (temp == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    // Step 3: Traverse and print all nodes
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    // Step 4: Indicate end of queue
    printf("NULL\n");
}

// Main function (Menu-driven program)
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                // Take value from user and insert into queue
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                // Remove element from front
                dequeue();
                break;

            case 3:
                // Display queue elements
                display();
                break;

            case 4:
                // Exit program
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}