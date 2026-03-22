// Day 49 - Question 1: BST Insert
// Close
// Problem: BST Insert

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

/* BST Node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Create node */
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

/* BST Insert */
struct Node* insert(struct Node* root, int val) {

    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);

    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

/* Inorder traversal (to verify BST) */
void inorder(struct Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Main */
int main() {

    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}