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

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;

    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 4);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}