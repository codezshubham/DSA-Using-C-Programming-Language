#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define the structure for a queue node
struct Node {
    struct TreeNode* val;
    struct Node* next;
};

// Define the structure for the queue (linked list implementation)
struct QueueLL {
    struct Node* head;
    struct Node* tail;
    int size;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Initialize the queue
void initializeQueue(struct QueueLL* q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

// Function to create a new queue node
struct Node* createNode(struct TreeNode* val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

// Function to add an element to the queue
void add(struct QueueLL* q, struct TreeNode* val) {
    struct Node* temp = createNode(val);
    if (q->size == 0) {
        q->head = q->tail = temp;
    } else {
        q->tail->next = temp;
        q->tail = temp;
    }
    q->size++;
}

// Function to remove an element from the queue
struct TreeNode* removeElement(struct QueueLL* q) {
    if (q->size == 0) {
        printf("Queue is Empty\n");
        return NULL;
    }
    struct TreeNode* x = q->head->val;
    struct Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->size--;
    return x;
}

// Check if the queue is empty
int isEmpty(struct QueueLL* q) {
    return q->size == 0;
}

// BFS traversal using the custom queue
void bfs(struct TreeNode* root) {
    struct QueueLL q;
    initializeQueue(&q);

    if (root != NULL) {
        add(&q, root);
    }

    while (!isEmpty(&q)) {
        struct TreeNode* temp = removeElement(&q);
        printf("%d ", temp->val);

        if (temp->left != NULL) {
            add(&q, temp->left);
        }
        if (temp->right != NULL) {
            add(&q, temp->right);
        }
    }
    printf("\n");
}

// Main function to test the BFS implementation
int main() {
    struct TreeNode* root = createTreeNode(5);
    root->left = createTreeNode(4);
    root->right = createTreeNode(7);
    root->left->left = createTreeNode(2);
    root->left->right = createTreeNode(3);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(1);

    bfs(root);

    // Remember to free allocated memory to avoid memory leaks
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
