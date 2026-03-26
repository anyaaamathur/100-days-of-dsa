// Day 53 - Question 1: Print Binary Tree Vertical Order
// Close
// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

/* Tree Node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Queue for building tree */
struct Node* queue[MAX];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

/* Create node */
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

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

/* Queue for BFS with HD */
struct QNode {
    struct Node* node;
    int hd;
};

struct QNode q[MAX];
int f = 0, r = -1;

void push(struct Node* node, int hd) {
    r++;
    q[r].node = node;
    q[r].hd = hd;
}

struct QNode pop() {
    return q[f++];
}

int qEmpty() {
    return f > r;
}

/* Find min/max HD */
void findRange(struct Node* root, int hd, int* min, int* max) {

    if (root == NULL)
        return;

    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;

    findRange(root->left, hd - 1, min, max);
    findRange(root->right, hd + 1, min, max);
}

/* Vertical Order Traversal */
void verticalOrder(struct Node* root) {

    if (root == NULL)
        return;

    int minHD = 0, maxHD = 0;
    findRange(root, 0, &minHD, &maxHD);

    int width = maxHD - minHD + 1;

    int** result = (int**)malloc(width * sizeof(int*));
    int* size = (int*)calloc(width, sizeof(int));

    for (int i = 0; i < width; i++)
        result[i] = (int*)malloc(1000 * sizeof(int));

    push(root, -minHD);

    while (!qEmpty()) {

        struct QNode curr = pop();

        struct Node* node = curr.node;
        int hd = curr.hd;

        result[hd][size[hd]++] = node->data;

        if (node->left)
            push(node->left, hd - 1);

        if (node->right)
            push(node->right, hd + 1);
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

/* Main */
int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}