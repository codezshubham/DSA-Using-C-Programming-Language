#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct QueueLL {
    struct Node* head;
    struct Node* tail;
    int size;
};

void initializeQueue(struct QueueLL* q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void add(struct QueueLL* q, int val) {
    struct Node* temp = createNode(val);
    if (q->size == 0) {
        q->head = q->tail = temp;
    } else {
        q->tail->next = temp;
        q->tail = temp;
    }
    q->size++;
}

int removeElement(struct QueueLL* q) {
    if (q->size == 0) {
        printf("Queue is Empty\n");
        return -1;
    }
    int x = q->head->val;
    struct Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->size--;
    return x;
}

int peek(struct QueueLL* q) {
    if (q->size == 0) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->head->val;
}

int getSize(struct QueueLL* q) {
    return q->size;
}

int isEmpty(struct QueueLL* q) {
    return q->size == 0;
}

void display(struct QueueLL* q) {
    if (q->size == 0) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node* temp = q->head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void cleanupQueue(struct QueueLL* q) {
    struct Node* temp = q->head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

int main() {
    struct QueueLL q;
    initializeQueue(&q);

    add(&q, 1);
    add(&q, 2);
    add(&q, 3);
    add(&q, 4);
    add(&q, 5);

    display(&q);

    removeElement(&q);
    display(&q);

    printf("%d\n", peek(&q));

    cleanupQueue(&q);

    return 0;
}
