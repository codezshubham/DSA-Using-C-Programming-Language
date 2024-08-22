#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct LLStack {
    struct Node* head;
    int size;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void initLLStack(struct LLStack* st) {
    st->head = NULL;
    st->size = 0;
}

void push(struct LLStack* st, int x) {
    struct Node* temp = createNode(x);
    temp->next = st->head;
    st->head = temp;
    st->size++;
}

int pop(struct LLStack* st) {
    if (st->head == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    int x = st->head->val;
    struct Node* temp = st->head;
    st->head = st->head->next;
    free(temp);
    st->size--;
    return x;
}

int peek(struct LLStack* st) {
    if (st->head == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    return st->head->val;
}

int getSize(struct LLStack* st) {
    return st->size;
}

int isEmpty(struct LLStack* st) {
    return st->head == NULL;
}

void displayRec(struct Node* h) {
    if (h == NULL) return;
    displayRec(h->next);
    printf("%d ", h->val);
}

void display(struct LLStack* st) {
    displayRec(st->head);
    printf("\n");
}

void revDisplay(struct LLStack* st) {
    struct Node* temp = st->head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct LLStack st;
    initLLStack(&st);
    push(&st, 4);
    display(&st);
    push(&st, 5);
    display(&st);
    push(&st, 6);
    display(&st);
    printf("%d\n", getSize(&st));
    pop(&st);
    display(&st);
    push(&st, 7);
    push(&st, 8);
    display(&st);
    return 0;
}
