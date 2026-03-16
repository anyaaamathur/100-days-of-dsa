// Day 43 - Question 1: Binary Tree Construction (Level Order)
// Close
// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers (-1 represents NULL)

// Output Format:
// - Print inorder traversal of the constructed tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 4 2 5 1 3 6

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

/* Tree Node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Queue for tree construction */
struct Node* queue[MAX];
int front = 0, rear = -1;

/* Queue ops */
void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

/* Create new node */
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

/* Build tree from level order */
struct Node* buildTree(int arr[], int n) {

    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n && !isEmpty()) {

        struct Node* curr = dequeue();

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

/* Inorder traversal */
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

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    inorder(root);

    return 0;
}
