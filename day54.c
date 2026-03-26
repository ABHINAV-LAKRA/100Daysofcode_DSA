#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* queue[1000];
int front = 0, rear = 0;

void push(struct Node* node) {
    queue[rear++] = node;
}

struct Node* pop() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void zigzagTraversal(struct Node* root) {
    if (!root) return;

    int leftToRight = 1;
    push(root);

    while (!isEmpty()) {
        int size = rear - front;
        int arr[1000];

        for (int i = 0; i < size; i++) {
            struct Node* curr = pop();

            int index = leftToRight ? i : size - i - 1;
            arr[index] = curr->data;

            if (curr->left) push(curr->left);
            if (curr->right) push(curr->right);
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    zigzagTraversal(root);
    return 0;
}