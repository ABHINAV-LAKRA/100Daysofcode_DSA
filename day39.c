#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int cap) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (int*)malloc(sizeof(int) * cap);
    h->size = 0;
    h->capacity = cap;
    return h;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void up(MinHeap* h, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p] <= h->arr[i]) break;
        swap(&h->arr[p], &h->arr[i]);
        i = p;
    }
}

void down(MinHeap* h, int i) {
    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int s = i;

        if (l < h->size && h->arr[l] < h->arr[s]) s = l;
        if (r < h->size && h->arr[r] < h->arr[s]) s = r;

        if (s == i) break;
        swap(&h->arr[i], &h->arr[s]);
        i = s;
    }
}

void insert(MinHeap* h, int val) {
    if (h->size == h->capacity) return;

    h->arr[h->size] = val;
    up(h, h->size);
    h->size++;
}

int extractMin(MinHeap* h) {
    if (h->size == 0) return -1;

    int val = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    down(h, 0);

    return val;
}

int getMin(MinHeap* h) {
    if (h->size == 0) return -1;
    return h->arr[0];
}

int isEmpty(MinHeap* h) {
    return h->size == 0;
}