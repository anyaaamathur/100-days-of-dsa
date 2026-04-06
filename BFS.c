// Day 64 - Question 1: Breadth First Search (BFS)
// Close
// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <stdio.h>
#include <stdlib.h>

/* Node for adjacency list */
struct Node {
    int data;
    struct Node* next;
};

/* Queue */
int queue[10000];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

/* Create node */
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

/* Add edge (undirected) */
void addEdge(struct Node* adj[], int u, int v) {

    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

/* BFS */
void BFS(struct Node* adj[], int n, int start) {

    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {

        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];

        while (temp != NULL) {

            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }

            temp = temp->next;
        }
    }
}

/* Main */
int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int s;
    scanf("%d", &s);

    BFS(adj, n, s);

    return 0;
}