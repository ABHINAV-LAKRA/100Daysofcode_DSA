#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* rear;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->rear = NULL;
    return q;
}

void enqueue(CircularQueue* q, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;

    if (q->rear == NULL) {
        temp->next = temp;
        q->rear = temp;
        return;
    }

    temp->next = q->rear->next;
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(CircularQueue* q) {
    if (q->rear == NULL) return -1;

    Node* front = q->rear->next;
    int val = front->data;

    if (q->rear == front) {
        q->rear = NULL;
    } else {
        q->rear->next = front->next;
    }

    free(front);
    return val;
}

int peek(CircularQueue* q) {
    if (q->rear == NULL) return -1;
    return q->rear->next->data;
}

int isEmpty(CircularQueue* q) {
    return q->rear == NULL;
}