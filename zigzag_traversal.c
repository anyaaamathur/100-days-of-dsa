// Day 54 - Question 1: Zigzag Traversal
// Close
// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.

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

/* Build tree from level order (-1 = NULL) */
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

/* Zigzag Traversal */
void zigzag(struct Node* root) {

    if (root == NULL)
        return;

    struct Node* q[MAX];
    int f = 0, r = -1;

    q[++r] = root;

    int leftToRight = 1;

    while (f <= r) {

        int levelSize = r - f + 1;
        int temp[levelSize];

        for (int i = 0; i < levelSize; i++) {

            struct Node* node = q[f++];

            int index = leftToRight ? i : (levelSize - 1 - i);
            temp[index] = node->data;

            if (node->left)
                q[++r] = node->left;

            if (node->right)
                q[++r] = node->right;
        }

        for (int i = 0; i < levelSize; i++)
            printf("%d ", temp[i]);

        leftToRight = !leftToRight;
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

    zigzag(root);

    return 0;
}