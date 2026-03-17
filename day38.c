#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(Deque* dq, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = dq->front;

    if (dq->front) dq->front->prev = temp;
    else dq->rear = temp;

    dq->front = temp;
    dq->size++;
}

void push_back(Deque* dq, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = dq->rear;

    if (dq->rear) dq->rear->next = temp;
    else dq->front = temp;

    dq->rear = temp;
    dq->size++;
}

int pop_front(Deque* dq) {
    if (!dq->front) return -1;

    Node* temp = dq->front;
    int val = temp->data;

    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;

    free(temp);
    dq->size--;
    return val;
}

int pop_back(Deque* dq) {
    if (!dq->rear) return -1;

    Node* temp = dq->rear;
    int val = temp->data;

    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;

    free(temp);
    dq->size--;
    return val;
}

int front(Deque* dq) {
    if (!dq->front) return -1;
    return dq->front->data;
}

int back(Deque* dq) {
    if (!dq->rear) return -1;
    return dq->rear->data;
}

int empty(Deque* dq) {
    return dq->size == 0;
}

int size(Deque* dq) {
    return dq->size;
}

void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

void reverse(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    temp = dq->front;
    dq->front = dq->rear;
    dq->rear = temp;
}