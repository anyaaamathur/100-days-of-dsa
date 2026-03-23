// Day 50 - Question 1: BST Search
// Close
// Problem: BST Search

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

/* BST Search */
int searchBST(struct Node* root, int key) {

    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
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

    /* Key to search */
    int key;
    scanf("%d", &key);

    if (searchBST(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}