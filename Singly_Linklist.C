#include <stdio.h>
#include <stdlib.h>

void inserAtBeginning();
void display();
void insertAtEnd();
void deleteAtBegin();
void deleteAtEnd();

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

int main()
{
    int choice;

    while (1)
    {
        printf("Linked List Menu: \n");


        printf("\n1.INSERT AT BEGINNING");
        printf("\n2.DISPLAY THE LINKED LIST");
        printf("\n3.INSERT AT END");
        printf("\n4.DELETE AT BEGIN");
        printf("\n5.DELETE AT END");
        printf("\n6.exit");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            inserAtBeginning();
            break;

        case 2:
            display();
            break;

        case 3:
            insertAtEnd();
            break;

        case 4:
            deleteAtBegin();
            break;

        case 5:
            deleteAtEnd();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
}

void inserAtBeginning()
{

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the value for new node: \n");
    scanf("%d", &newNode -> data);

    newNode -> next = head;

    head = newNode;
}

void display() {

    struct Node* temp;

    temp = head;

    while(temp != NULL) {
        printf("Data : %d\n", temp -> data);
        printf("Address of current node: %p\n", temp);
        printf("Address of next node: %p\n\n", temp -> next);
        temp = temp -> next;
    }
}

void insertAtEnd() {

    struct Node* newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));

    printf("Enter the value for the new node: ");
    scanf("%d", &newNode -> data);

    newNode -> next = NULL;

    struct Node* temp = head;

    if(head == NULL) {
        head = newNode;
    }

    else {
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
    
}

void deleteAtBegin() {

    if(head == NULL) {
        printf("\nList is empty\n");
    }

    else {
        struct Node* temp = head;
    
        head = head -> next;
    
        free(temp);
    }

}

void deleteAtEnd() {

    if(head == NULL) {
        printf("\nList is empty\n");
    }

    else if(head -> next == NULL) {
        free(head);
        head = NULL;
    }

    else {
        struct Node* temp = head;
        struct Node* prev;
    
        while (temp -> next != NULL) {
            prev = temp;
            temp = temp -> next;
        }
        
        free(temp);
        prev -> next = NULL;
    }
}