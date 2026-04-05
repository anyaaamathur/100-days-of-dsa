// Day 63 - Question 1: Depth First Search (DFS)
// Close
// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order

#include <stdio.h>
#include <stdlib.h>

/* Node for adjacency list */
struct Node {
    int data;
    struct Node* next;
};

/* DFS function */
void DFS(int v, struct Node* adj[], int visited[]) {

    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];

    while (temp != NULL) {

        if (!visited[temp->data]) {
            DFS(temp->data, adj, visited);
        }

        temp = temp->next;
    }
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

/* Main */
int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    /* input edges */
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int s;
    scanf("%d", &s);

    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(s, adj, visited);

    return 0;
}