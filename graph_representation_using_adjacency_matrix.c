// Day 62 - Question 1: Graph Representation Using Adjacency List
// Close
// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex

#include <stdio.h>
#include <stdlib.h>

/* Node of adjacency list */
struct Node {
    int data;
    struct Node* next;
};

/* Create new node */
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

/* Add edge */
void addEdge(struct Node* adj[], int u, int v) {

    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

/* Print adjacency list */
void printGraph(struct Node* adj[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);

        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

/* Main */
int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    /* initialize heads to NULL */
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    /* input edges */
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        addEdge(adj, v, u);  // remove this line for directed graph
    }

    printGraph(adj, n);

    return 0;
}