// Day 51 - Question 1: Lowest Common Ancestor in BST
// Close
// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

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

/* Insert into BST */
struct Node* insert(struct Node* root, int val) {

    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

/* LCA in BST */
struct Node* LCA(struct Node* root, int n1, int n2) {

    if (root == NULL)
        return NULL;

    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

/* Main */
int main() {

    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    /* Build BST */
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node* lca = LCA(root, a, b);

    printf("%d", lca->data);

    return 0;
}