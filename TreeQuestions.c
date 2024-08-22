#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void nthLevel(Node* root, int n) {
    if (root == NULL) return;

    if (n == 1) {
        printf("%d ", root->val);
        return;
    }
    nthLevel(root->left, n - 1);
    nthLevel(root->right, n - 1);
}

int main() {
    Node* root = createNode(5);
    Node* a = createNode(4);
    Node* b = createNode(7);
    root->left = a;
    root->right = b;
    Node* c = createNode(2);
    Node* d = createNode(3);
    a->left = c;
    a->right = d;
    Node* e = createNode(6);
    Node* f = createNode(1);
    b->left = e;
    b->right = f;

    int level = height(root) + 1;
    for (int i = 1; i <= level; i++) {
        nthLevel(root, i);
        printf("\n");
    }

    // Free allocated memory to avoid memory leaks
    free(root);
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);

    return 0;
}
