#include <stdio.h>

#define SIZE 5   // Maximum size of the circular queue

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    // Check whether the queue is full or not
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Queue Overflow\n");
        return;
    }

    // If the queue is empty and the first element is being inserted,
    // both front and rear are set to 0
    if (front == -1) {
        front = rear = 0;
    }
    // If rear reaches the last index, move it back to index 0 (circular movement)
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    // Otherwise, move rear to the next position
    else {
        rear++;
    }

    // Store the value at the rear position
    queue[rear] = value;

    // Print the inserted element
    printf("Inserted: %d\n", value);
}

void dequeue() {
    // If the queue is empty, deletion is not possible (Underflow)
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    // The element at the front position is removed
    printf("Deleted: %d\n", queue[front]);

    // If there is only one element in the queue and it gets deleted,
    // the queue becomes empty (front = rear = -1)
    if (front == rear) {
        front = rear = -1;
    }
    // If front reaches the last index, move it to index 0 (circular movement)
    else if (front == SIZE - 1) {
        front = 0;
    }
    // Otherwise, move front to the next position
    else {
        front++;
    }
}

void display() {
    // If the queue is empty, nothing is printed
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    // Traversal always starts from the front
    int i = front;

    // Print all elements one by one
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);

        // Stop when rear is reached
        if (i == rear) {
            break;
        }

        // Move index circularly
        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}