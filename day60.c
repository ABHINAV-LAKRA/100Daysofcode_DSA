#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isComplete(struct Node* root, int index, int total) {
    if (!root) return 1;

    if (index >= total) return 0;

    return isComplete(root->left, 2 * index + 1, total) &&
           isComplete(root->right, 2 * index + 2, total);
}

int isHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right)
        return (root->data <= root->left->data);

    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isHeap(root->left) && isHeap(root->right);

    return 0;
}

int isMinHeap(struct Node* root) {
    int total = countNodes(root);

    if (isComplete(root, 0, total) && isHeap(root))
        return 1;

    return 0;
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);

    if (isMinHeap(root))
        printf("Yes, it is a Min Heap\n");
    else
        printf("No, it is NOT a Min Heap\n");

    return 0;
}