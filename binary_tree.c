/* Binary Tree Implementation*/
#include <stdio.h>
#include <stdlib.h>

// Structure of a binary tree node
struct Node
{
    int data;              // stores value of the node
    struct Node *Left;     // pointer to left child
    struct Node *Right;    // pointer to right child
};

// Function to create a new node
struct Node *createNode(int value)
{
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Assign value to the node
    newNode->data = value;

    // Initialize left and right pointers as NULL
    newNode->Left = NULL;
    newNode->Right = NULL;

    // Return the address of the new node
    return newNode;
}

// Preorder traversal: Root -> Left -> Right
void preorder(struct Node *root)
{
    // Base case: if node is NULL, stop recursion
    if (root == NULL)
    {
        return;
    }

    // Step 1: Process root (print data)
    printf("%d ", root->data);

    // Step 2: Traverse left subtree
    preorder(root->Left);

    // Step 3: Traverse right subtree
    preorder(root->Right);
}   

// Inorder traversal: Left -> Root -> Right
void inorder(struct Node *root)
{
    // Base case: if node is NULL, stop recursion
    if (root == NULL)
    {
        return;
    }

    // Step 1: Traverse left subtree
    inorder(root->Left);

    // Step 2: Process root (print data)
    printf("%d ", root->data);

    // Step 3: Traverse right subtree
    inorder(root->Right);
}

// Postorder traversal: Left -> Right -> Root
void postorder(struct Node *root)
{
    // Base case: if node is NULL, stop recursion
    if (root == NULL)
    {
        return;
    }

    // Step 1: Traverse left subtree
    postorder(root->Left);

    // Step 2: Traverse right subtree
    postorder(root->Right);

    // Step 3: Process root (print data)
    printf("%d ", root->data);
}

int main()
{
    // Create root node
    struct Node *root = createNode(10);

    // Create left and right children of root
    root->Left = createNode(20);
    root->Right = createNode(30);

    // Create children of node 20
    root->Left->Left = createNode(40);
    root->Left->Right = createNode(50);

    // Create right child of node 30
    root->Right->Right = createNode(60);

    // Call preorder traversal
    printf("Preorder: ");
    preorder(root);

    // Call inorder traversal
    printf("\nInorder: ");
    inorder(root);

    // Call postorder traversal
    printf("\nPostorder: ");
    postorder(root);

    return 0;
}