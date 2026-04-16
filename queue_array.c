/* Queue Using Array*/
#include <stdio.h>

#define MAX 5   // Maximum size of the queue

int queue[MAX];   // Array to store queue elements
int front = -1;   // Points to the first element
int rear = -1;    // Points to the last element

// Function to insert element into queue
void enqueue(int value) {

    // Check if queue is full
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    // If queue is empty, initialize front
    if (front == -1) {
        front = 0;
    }

    // Move rear forward and insert element
    rear++;
    queue[rear] = value;

    printf("Inserted: %d\n", value);
}

// Function to remove element from queue
void dequeue() {

    // Check if queue is empty
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    // Print the element to be deleted
    printf("Deleted: %d\n", queue[front]);

    // If only one element was present, reset queue
    if (front == rear) {
        front = rear = -1;
    } else {
        // Move front forward
        front++;
    }
}

// Function to display queue elements
void display() {

    // Check if queue is empty
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    // Print elements from front to rear
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

// Function to show front element
void peek() {

    // Check if queue is empty
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

int main() {
    int choice, value;

    while (1) {

        // Display menu
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}