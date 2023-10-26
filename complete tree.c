#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a binary tree is complete
int isComplete(struct TreeNode* root, int index, int nodeCount) {
    // An empty tree is considered complete
    if (root == NULL) {
        return 1;
    }

    // If the index of the current node is greater than or equal to the total node count,
    // the tree is not complete
    if (index >= nodeCount) {
        return 0;
    }

    // Recursively check the left and right subtrees
    return isComplete(root->left, 2 * index + 1, nodeCount) &&
           isComplete(root->right, 2 * index + 2, nodeCount);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    int totalNodes = 6;

    if (isComplete(root, 0, totalNodes)) {
        printf("The binary tree is complete.\n");
    } else {
        printf("The binary tree is not complete.\n");
    }

    return 0;
}
