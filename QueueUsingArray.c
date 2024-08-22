#include <stdio.h>
#include <stdlib.h>

struct QueueArray {
    int *arr;
    int f;  // Front
    int r;  // Rear
    int size;
};

void initializeQueue(struct QueueArray *q) {
    q->arr = (int *)malloc(5 * sizeof(int));
    q->f = -1;
    q->r = -1;
    q->size = 0;
}

void add(struct QueueArray *q, int val) {
    if (q->r == 4) {
        printf("Queue is full\n");
        return;
    }

    if (q->f == -1) {
        q->f = q->r = 0;
        q->arr[0] = val;
    } else {
        q->arr[++q->r] = val;
    }

    q->size++;
}

int removeElement(struct QueueArray *q) {
    if (q->size == 0) {
        printf("Queue Is Empty\n");
        return -1;
    }

    int x = q->arr[q->f++];
    q->size--;
    return x;
}

int peek(struct QueueArray *q) {
    if (q->size == 0) {
        printf("Queue Is Empty\n");
        return -1;
    }
    return q->arr[q->f];
}

int getSize(struct QueueArray *q) {
    return q->size;
}

int isEmpty(struct QueueArray *q) {
    return q->size == 0;
}

void display(struct QueueArray *q) {
    if (q->size == 0) {
        printf("Queue Is Empty\n");
        return;
    }

    for (int i = q->f; i <= q->r; i++) {
        printf("%d ", q->arr[i]);
    }

    printf("\n");
}

void cleanupQueue(struct QueueArray *q) {
    free(q->arr);
}

int main() {
    struct QueueArray q;
    initializeQueue(&q);

    add(&q, 1);
    add(&q, 2);
    add(&q, 3);
    add(&q, 4);
    add(&q, 5);

    display(&q);

    removeElement(&q);
    display(&q);

    printf("%d\n", getSize(&q));

    cleanupQueue(&q);

    return 0;
}
