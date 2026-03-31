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
    node->left = node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* buildTreeHelper(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if(inStart > inEnd)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = createNode(rootVal);

    if(inStart == inEnd)
        return root;

    int index = findIndex(inorder, inStart, inEnd, rootVal);

    root->right = buildTreeHelper(inorder, postorder, index + 1, inEnd, postIndex);
    root->left = buildTreeHelper(inorder, postorder, inStart, index - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildTreeHelper(inorder, postorder, 0, n - 1, &postIndex);
}

void printPreorder(struct TreeNode* root) {
    if(root == NULL)
        return;

    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = 5;

    struct TreeNode* root = buildTree(inorder, postorder, n);

    printf("Preorder of constructed tree: ");
    printPreorder(root);

    return 0;
}