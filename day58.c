#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    struct TreeNode* root = newNode(preorder[preStart]);

    int index = findIndex(inorder, inStart, inEnd, root->val);
    int leftSize = index - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, index - 1);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, index + 1, inEnd);

    return root;
}

void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};

    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = build(preorder, 0, n - 1,
                                 inorder, 0, n - 1);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}