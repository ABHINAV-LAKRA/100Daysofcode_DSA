#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void reverseQueue() {
    while (front <= rear)
        push(dequeue());

    while (top != -1)
        enqueue(pop());
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    reverseQueue();

    display();
    return 0;
}