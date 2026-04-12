#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if (table[newIndex] == -1) {
            table[newIndex] = key;
            return;
        }
    }

    printf("Hash Table Full, cannot insert %d\n", key);
}

int search(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if (table[newIndex] == key)
            return newIndex;

        if (table[newIndex] == -1)
            return -1;
    }

    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != -1)
            printf("%d -> %d\n", i, table[i]);
        else
            printf("%d -> EMPTY\n", i);
    }
}

int main() {
    init();

    insert(23);
    insert(43);
    insert(13);
    insert(27);

    display();

    int key = 43;
    int pos = search(key);

    if (pos != -1)
        printf("Key %d found at index %d\n", key, pos);
    else
        printf("Key not found\n");

    return 0;
}