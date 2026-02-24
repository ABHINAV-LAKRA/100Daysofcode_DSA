#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    if (head == NULL) return head;

    if (head->data == key) {
        struct Node* del = head;
        head = head->next;
        free(del);
        return head;
    }

    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data != key)
        curr = curr->next;

    if (curr->next != NULL) {
        struct Node* del = curr->next;
        curr->next = del->next;
        free(del);
    }

    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 20);
    head = insertEnd(head, 40);

    printf("Original list: ");
    display(head);

    head = deleteFirstOccurrence(head, 20);

    printf("\nAfter deletion: ");
    display(head);

    return 0;
}