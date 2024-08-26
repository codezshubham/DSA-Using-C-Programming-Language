#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for pre-order traversal
void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

// Function for in-order traversal
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

// Function for post-order traversal
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

// Main function
int main() {
    // Creating nodes and constructing the binary tree
    Node* root = createNode(5);
    Node* a = createNode(3);
    Node* b = createNode(7);
    root->left = a;
    root->right = b;
    Node* c = createNode(2);
    Node* d = createNode(4);
    a->left = c;
    a->right = d;
    Node* e = createNode(6);
    Node* f = createNode(8);
    b->left = e;
    b->right = f;

    // Perform in-order traversal
    inOrder(root);
    printf("\n");

    // Uncomment the lines below to perform pre-order and post-order traversals
    // preOrder(root);
    // printf("\n");
    // postOrder(root);
    // printf("\n");

    // Deallocate memory to prevent memory leaks
    free(f);
    free(e);
    free(d);
    free(c);
    free(b);
    free(a);
    free(root);

    return 0;
}