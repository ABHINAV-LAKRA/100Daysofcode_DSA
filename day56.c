#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) return 1;
    if (left == NULL || right == NULL) return 0;

    if (left->val != right->val) return 0;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

int isSymmetric(struct TreeNode* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    if (isSymmetric(root))
        printf("Tree is Symmetric\n");
    else
        printf("Tree is Not Symmetric\n");

    return 0;
}