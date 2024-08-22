#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Non-recursive preorder traversal using an array as a stack
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    // Define the maximum size of the stack (can be increased if needed)
    int maxSize = 100;
    Node* stack[maxSize];
    int top = -1;

    // Push the root node onto the stack
    stack[++top] = root;

    while (top >= 0) {
        // Pop a node from the stack
        Node* current = stack[top--];

        // Process the current node
        printf("%d ", current->val);

        // Push right child first so that left child is processed first
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;

    // Define the maximum size of the stack (can be increased if needed)
    int maxSize = 100;
    Node* stack[maxSize];
    int top = -1;
    Node* current = root;

    while (current != NULL || top >= 0) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // Current must be NULL at this point
        current = stack[top--];
        printf("%d ", current->val);

        // Visit the right subtree
        current = current->right;
    }
}

// Main function to test the traversal
int main() {
    // Creating a simple binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform non-recursive preorder traversal
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown for simplicity)

    return 0;
}
