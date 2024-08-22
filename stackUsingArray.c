#include <stdio.h>

#define MAX_SIZE 4

struct Stack {
    int arr[MAX_SIZE];
    int idx;
};

void initStack(struct Stack *st) {
    st->idx = 0;
}

void push(struct Stack *st, int x) {
    if (st->idx == MAX_SIZE) {
        printf("Stack Is Full\n");
        return;
    }
    st->arr[st->idx] = x;
    st->idx++;
}

int peek(struct Stack *st) {
    if (st->idx == 0) {
        printf("Stack Is Empty\n");
        return -1;
    }
    return st->arr[st->idx - 1];
}

int pop(struct Stack *st) {
    if (st->idx == 0) {
        printf("Stack Is Empty\n");
        return -1;
    }
    int top = st->arr[st->idx - 1];
    st->arr[st->idx - 1] = 0;
    st->idx--;
    return top;
}

int size(struct Stack *st) {
    return st->idx;
}

int isEmpty(struct Stack *st) {
    return st->idx == 0;
}

int isFull(struct Stack *st) {
    return st->idx == MAX_SIZE;
}

int capacity() {
    return MAX_SIZE;
}

void display(struct Stack *st) {
    if (isEmpty(st)) {
        printf("Stack Is Empty\n");
    }
    for (int i = 0; i <= st->idx - 1; i++) {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack st;
    initStack(&st);
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    display(&st);
    printf("%d\n", isFull(&st));
    push(&st, 5);
    pop(&st);
    printf("%d\n", peek(&st));
    printf("%d\n", capacity());
    return 0;
}
