#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;              // Stores value
    struct Node* prev;     // Pointer to previous node
    struct Node* next;     // Pointer to next node
};

// Head pointer
struct Node* head = NULL;

// Insert at end
void insert() {
    int value;

    // Step 1: Take input from user
    printf("Enter value: ");
    scanf("%d", &value);

    // Step 2: Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Step 3: Assign data and initialize pointers
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Step 4: If list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Step 5: Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Step 6: Link new node at end
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from end
void deleteEnd() {

    // Step 1: Check if list is empty
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node* temp = head;

    // Step 2: If only one node
    if (temp->next == NULL) {
        printf("Deleted: %d\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    // Step 3: Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Step 4: Print deleted value
    printf("Deleted: %d\n", temp->data);

    // Step 5: Update previous node
    temp->prev->next = NULL;

    // Step 6: Free memory
    free(temp);
}

// Display forward
void displayForward() {
    struct Node* temp = head;

    // Step 1: Check empty
    if (temp == NULL) {
        printf("List is Empty\n");
        return;
    }

    // Step 2: Traverse forward
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display backward
void displayBackward() {
    struct Node* temp = head;

    // Step 1: Check empty
    if (temp == NULL) {
        printf("List is Empty\n");
        return;
    }

    // Step 2: Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Step 3: Traverse backward
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function (Menu driven)
int main() {
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete from End\n");
        printf("3. Display Forward\n");
        printf("4. Display Backward\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                insert();
                break;

            case 2:
                deleteEnd();
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}