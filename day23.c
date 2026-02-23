#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* temp = createNode(value);
    if (head == NULL) return temp;

    struct Node* curr = head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = temp;
    return head;
}

struct Node* mergeLists(struct Node* a, struct Node* b) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (a != NULL && b != NULL) {
        struct Node* temp;
        if (a->data <= b->data) {
            temp = createNode(a->data);
            a = a->next;
        } else {
            temp = createNode(b->data);
            b = b->next;
        }

        if (result == NULL) {
            result = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    while (a != NULL) {
        tail->next = createNode(a->data);
        tail = tail->next;
        a = a->next;
    }

    while (b != NULL) {
        tail->next = createNode(b->data);
        tail = tail->next;
        b = b->next;
    }

    return result;
}

void display(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* merged = NULL;

    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);

    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);

    merged = mergeLists(list1, list2);

    display(merged);

    return 0;
}