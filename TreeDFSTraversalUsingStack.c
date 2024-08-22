#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Stack structure for handling nodes
typedef struct Stack {
    Node** data;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (Node**)malloc(capacity * sizeof(Node*));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to push a node onto the stack
void push(Stack* stack, Node* node) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++(stack->top)] = node;
    }
}

// Function to pop a node from the stack
Node* pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    }
    return NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Preorder traversal function
int* preorderTraversal(Node* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    Stack* stack = createStack(100);  // Create a stack with an arbitrary size
    int* result = (int*)malloc(100 * sizeof(int));  // Arbitrary size for the result array

    push(stack, root);

    while (!isEmpty(stack)) {
        Node* temp = pop(stack);
        result[(*returnSize)++] = temp->val;

        if (temp->right != NULL) {
            push(stack, temp->right);
        }
        if (temp->left != NULL) {
            push(stack, temp->left);
        }
    }

    free(stack->data);
    free(stack);

    return result;
}

// Inorder traversal function
int* inorderTraversal(Node* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    Stack* stack = createStack(100);
    int* result = (int*)malloc(100 * sizeof(int));
    Node* curr = root;

    while (!isEmpty(stack) || curr != NULL) {
        if (curr != NULL) {
            push(stack, curr);
            curr = curr->left;
        } else {
            curr = pop(stack);
            result[(*returnSize)++] = curr->val;
            curr = curr->right;
        }
    }

    free(stack->data);
    free(stack);

    return result;
}

// Postorder traversal function
int* postorderTraversal(Node* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    Stack* stack1 = createStack(100);
    Stack* stack2 = createStack(100);
    int* result = (int*)malloc(100 * sizeof(int));

    push(stack1, root);

    while (!isEmpty(stack1)) {
        Node* temp = pop(stack1);
        push(stack2, temp);

        if (temp->left != NULL) {
            push(stack1, temp->left);
        }
        if (temp->right != NULL) {
            push(stack1, temp->right);
        }
    }

    while (!isEmpty(stack2)) {
        Node* temp = pop(stack2);
        result[(*returnSize)++] = temp->val;
    }

    free(stack1->data);
    free(stack1);
    free(stack2->data);
    free(stack2);

    return result;
}

int main() {
    // Create nodes
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

    int returnSize;
    
    // Preorder Traversal
    int* resultPreorder = preorderTraversal(root, &returnSize);
    printf("Preorder Traversal:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", resultPreorder[i]);
    }
    printf("\n");

    // Inorder Traversal
    int* resultInorder = inorderTraversal(root, &returnSize);
    printf("Inorder Traversal:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", resultInorder[i]);
    }
    printf("\n");

    // Postorder Traversal
    int* resultPostorder = postorderTraversal(root, &returnSize);
    printf("Postorder Traversal:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", resultPostorder[i]);
    }
    printf("\n");

    // Free allocated memory
    free(resultPreorder);
    free(resultInorder);
    free(resultPostorder);
    free(root);
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);

    return 0;
}
