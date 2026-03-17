#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPQ(int cap) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->arr = (int*)malloc(sizeof(int) * cap);
    pq->size = 0;
    pq->capacity = cap;
    return pq;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void up(PriorityQueue* pq, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (pq->arr[p] <= pq->arr[i]) break;
        swap(&pq->arr[p], &pq->arr[i]);
        i = p;
    }
}

void down(PriorityQueue* pq, int i) {
    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int s = i;

        if (l < pq->size && pq->arr[l] < pq->arr[s]) s = l;
        if (r < pq->size && pq->arr[r] < pq->arr[s]) s = r;

        if (s == i) break;
        swap(&pq->arr[i], &pq->arr[s]);
        i = s;
    }
}

void push(PriorityQueue* pq, int val) {
    if (pq->size == pq->capacity) return;

    pq->arr[pq->size] = val;
    up(pq, pq->size);
    pq->size++;
}

int pop(PriorityQueue* pq) {
    if (pq->size == 0) return -1;

    int val = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    down(pq, 0);

    return val;
}

int peek(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    return pq->arr[0];
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}