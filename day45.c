#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    return (left > right ? left : right) + 1;
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    int height = maxDepth(root);
    printf("Height of tree: %d\n", height);

    return 0;
}