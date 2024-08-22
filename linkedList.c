#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int size;
};

void initLinkedList(struct LinkedList* ll) {
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct LinkedList* ll, int val) {
    struct Node* temp = createNode(val);

    if (ll->head == NULL) {
        ll->head = temp;
        ll->tail = temp;
    } else {
        ll->tail->next = temp;
        ll->tail = temp;
    }
    ll->size++;
}

void insertAtBegin(struct LinkedList* ll, int val) {
    struct Node* temp = createNode(val);

    if (ll->head == NULL) {
        ll->head = temp;
        ll->tail = temp;
    } else {
        temp->next = ll->head;
        ll->head = temp;
    }
    ll->size++;
}

void insertAt(struct LinkedList* ll, int idx, int val) {
    struct Node* t = createNode(val);
    struct Node* temp = ll->head;

    if (idx == 0) {
        insertAtBegin(ll, val);
        return;
    } else if (idx == ll->size) {
        insertAtEnd(ll, val);
        return;
    } else if (idx < 0 || idx > ll->size) {
        printf("Wrong Index\n");
        return;
    } else {
        for (int i = 1; i <= idx - 1; i++) {
            temp = temp->next;
        }

        t->next = temp->next;
        temp->next = t;
    }
    ll->size++;
}

void deleteAtBegin(struct LinkedList* ll) {
    if (ll->head == NULL) {
        return;
    }
    struct Node* temp = ll->head;
    ll->head = ll->head->next;
    free(temp);
    ll->size--;
}

void deleteAtEnd(struct LinkedList* ll) {
    if (ll->head == NULL) {
        return;
    }
    struct Node* temp = ll->head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    ll->tail = temp;
    ll->size--;
}

void deleteAt(struct LinkedList* ll, int idx) {
    struct Node* temp = ll->head;

    for (int i = 1; i <= idx - 1; i++) {
        temp = temp->next;
    }

    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    ll->size--;
}

int getAt(struct LinkedList* ll, int idx) {
    struct Node* temp = ll->head;

    for (int i = 1; i <= idx; i++) {
        temp = temp->next;
    }
    return temp->data;
}

void display(struct LinkedList* ll) {
    struct Node* temp = ll->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList ll;
    initLinkedList(&ll);
    insertAtEnd(&ll, 7);
    display(&ll);
    insertAtEnd(&ll, 6);
    display(&ll);
    insertAtBegin(&ll, 5);
    display(&ll);
    insertAtBegin(&ll, 4);
    display(&ll);
    insertAt(&ll, 4, 3);
    display(&ll);
    insertAt(&ll, 0, 3);
    display(&ll);
    deleteAt(&ll, 4);
    display(&ll);
    deleteAtBegin(&ll);
    display(&ll);
    deleteAtEnd(&ll);
    display(&ll);

    return 0;
}
