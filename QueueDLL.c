#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
    int size;
};

void initializeDeque(struct Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addToFront(struct Deque* dq, int data) {
    struct Node* newNode = createNode(data);
    if (dq->size == 0) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

void addToRear(struct Deque* dq, int data) {
    struct Node* newNode = createNode(data);
    if (dq->size == 0) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}

int removeFromFront(struct Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return -1;
    }
    int removedData = dq->front->data;
    if (dq->front == dq->rear) {
        free(dq->front);
        dq->front = dq->rear = NULL;
    } else {
        struct Node* temp = dq->front;
        dq->front = dq->front->next;
        dq->front->prev = NULL;
        free(temp);
    }
    dq->size--;
    return removedData;
}

int removeFromRear(struct Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return -1;
    }
    int removedData = dq->rear->data;
    if (dq->front == dq->rear) {
        free(dq->rear);
        dq->front = dq->rear = NULL;
    } else {
        struct Node* temp = dq->rear;
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
        free(temp);
    }
    dq->size--;
    return removedData;
}

int peekFront(struct Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->front->data;
}

int peekRear(struct Deque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->rear->data;
}

int getSize(struct Deque* dq) {
    return dq->size;
}

int isEmpty(struct Deque* dq) {
    return dq->size == 0;
}

int main() {
    struct Deque dq;
    initializeDeque(&dq);

    addToFront(&dq, 1);
    addToFront(&dq, 2);
    addToRear(&dq, 3);
    addToRear(&dq, 4);

    return 0;
}
