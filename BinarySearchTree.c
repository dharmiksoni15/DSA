#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    // If tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }

    // If value is smaller, go to left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If value is greater, go to right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged root pointer
    return root;
}

// Function to find the minimum value node in a subtree
struct Node* findMin(struct Node* root) {
    // Move to the leftmost node
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    // If the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If key is smaller than root data, search in left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // If key is greater than root data, search in right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // If key is equal to root data, this is the node to delete
    else {
        // Case 1: Node has no child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has only right child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Node has only left child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        // Find the inorder successor (smallest in right subtree)
        struct Node* temp = findMin(root->right);

        // Replace current node's data with successor's data
        root->data = temp->data;

        // Delete the inorder successor from right subtree
        root->right = deleteNode(root->right, temp->data);
    }

    // Return the updated root
    return root;
}

// Function for inorder traversal
// Inorder traversal of BST always prints values in sorted order
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to search a value in BST
int search(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == key) {
        return 1;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, deleteValue;

    // Ask user how many nodes they want to insert
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Take input for BST nodes
    printf("Enter %d values for BST:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Print BST before deletion
    printf("\nInorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    // Ask user which value to delete
    printf("Enter value to delete: ");
    scanf("%d", &deleteValue);

    // Check if the value exists before deleting
    if (search(root, deleteValue)) {
        root = deleteNode(root, deleteValue);

        printf("\nInorder traversal after deletion: ");
        inorder(root);
        printf("\n");
    } else {
        printf("\nValue not found in BST.\n");
    }

    return 0;
}