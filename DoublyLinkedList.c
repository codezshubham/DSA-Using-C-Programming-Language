#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyLL {
    struct Node* head;
    int size;
};

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* insertAtBegin(struct Node* head, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int val) {
    struct Node* temp = head;
    struct Node* tempe = (struct Node*)malloc(sizeof(struct Node));
    tempe->data = val;
    tempe->next = NULL;

    if (head == NULL) {
        return tempe;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = tempe;
    tempe->prev = temp;
    return head;
}

struct Node* insertAtIndex(struct Node* head, int idx, int val) {
    if (idx < 1) {
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; i < idx - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return head;
    }

    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->prev = temp;
    t->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = t;
    }

    temp->next = t;
    return head;
}

struct Node* deleteAtBegin(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    head = head->next;
    head->prev = NULL;
    free(head->prev);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int idx) {
    if (head == NULL || idx < 1) {
        return head;
    }

    if (idx == 1) {
        struct Node* newHead = head->next;
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
        free(head);
        return newHead;
    }

    struct Node* temp = head;
    for (int i = 1; i < idx - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return head;
    }

    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;

    if (temp->next != NULL) {
        temp->next->prev = temp;
    }

    free(toDelete);
    return head;
}

int main() {
    struct DoublyLL dl;
    dl.head = NULL;
    dl.size = 0;

    struct Node* a = (struct Node*)malloc(sizeof(struct Node));
    a->data = 5;
    a->next = NULL;
    a->prev = NULL;

    struct Node* b = (struct Node*)malloc(sizeof(struct Node));
    b->data = 4;
    b->next = NULL;
    b->prev = a;
    a->next = b;

    struct Node* c = (struct Node*)malloc(sizeof(struct Node));
    c->data = 3;
    c->next = NULL;
    c->prev = b;
    b->next = c;

    struct Node* d = (struct Node*)malloc(sizeof(struct Node));
    d->data = 2;
    d->next = NULL;
    d->prev = c;
    c->next = d;

    struct Node* e = (struct Node*)malloc(sizeof(struct Node));
    e->data = 1;
    e->next = NULL;
    e->prev = d;
    d->next = e;

    dl.head = a;

    display(dl.head);

    struct Node* x = insertAtBegin(dl.head, 7);
    display(x);

    struct Node* y = insertAtEnd(x, 6);
    display(y);

    struct Node* z = insertAtIndex(y, 5, 0);
    display(z);

    struct Node* w = deleteAtBegin(z);
    display(w);

    struct Node* v = deleteAtEnd(w);
    display(v);

    struct Node* u = deleteAtIndex(v, 2);
    display(u);

    // Clean up memory
    while (u != NULL) {
        struct Node* nextNode = u->next;
        free(u);
        u = nextNode;
    }

    return 0;
}
