#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* treeNode;
    int hd;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct QueueNode queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].treeNode = node;
    queue[rear].hd = hd;
    rear++;
}

struct QueueNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    int map[200][100];
    int count[200] = {0};

    int offset = 100;

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QueueNode temp = dequeue();
        struct Node* curr = temp.treeNode;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, temp.hd - 1);

        if (curr->right)
            enqueue(curr->right, temp.hd + 1);
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalOrder(root);

    return 0;
}