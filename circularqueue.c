#include <stdio.h>

#define SIZE 5

struct CircularQueueArray {
    int arr[SIZE];
    int n;
    int f;  // Front
    int r;  // Rear
    int size;
};

void initializeQueue(struct CircularQueueArray* q) {
    q->n = SIZE;
    q->f = -1;
    q->r = -1;
    q->size = 0;
}

void add(struct CircularQueueArray* q, int val) {
    if (q->size == q->n) {
        printf("Queue is full\n");
        return;
    } else if (q->f == -1) {
        q->f = q->r = 0;
        q->arr[0] = val;
    } else if (q->r == q->n - 1) {
        q->r = 0;
        q->arr[0] = val;
    } else {
        q->arr[++q->r] = val;
    }
    q->size++;
}

int removeElement(struct CircularQueueArray* q) {
    if (q->size == 0) {
        printf("Queue is Empty\n");
        return -1;
    }
    if (q->f == q->n - 1) {
        q->f = 0;
    }
    int x = q->arr[q->f];
    q->f++;
    q->size--;
    return x;
}

int peek(struct CircularQueueArray* q) {
    if (q->size == 0) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->arr[q->f];
}

int getSize(struct CircularQueueArray* q) {
    return q->size;
}

int isEmpty(struct CircularQueueArray* q) {
    return q->size == 0;
}

void display(struct CircularQueueArray* q) {
    if (q->size == 0) {
        printf("Queue Is Empty\n");
        return;
    } else {
        if (q->f <= q->r) {
            for (int i = q->f; i <= q->r; i++) {
                printf("%d ", q->arr[i]);
            }
        } else {
            // f to n-1
            for (int i = q->f; i < q->n; i++) {
                printf("%d ", q->arr[i]);
            }
            // 0 to r
            for (int i = 0; i <= q->r; i++) {
                printf("%d ", q->arr[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    struct CircularQueueArray q;
    initializeQueue(&q);

    add(&q, 1);
    add(&q, 2);
    add(&q, 3);
    add(&q, 4);
    add(&q, 5);
    display(&q);
    add(&q, 6);
    // removeElement(&q);  //2 3 4 5
    // display(&q);
    printf("%d\n", peek(&q));
    printf("%d\n", getSize(&q));

    return 0;
}
