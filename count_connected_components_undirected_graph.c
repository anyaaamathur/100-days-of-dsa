// Day 76 - Question 1: Count Connected Components (Undirected Graph)

// Problem Statement
// Using DFS or BFS, count number of connected components.

// Input Format
// n m
// edges

// Output Format
// Number of connected components.

// Sample Input
// 6 3
// 1 2
// 2 3
// 5 6

// Sample Output
// 3

// Explanation
// Components: {1,2,3}, {4}, {5,6}

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

/* Node */
struct Node {
    int data;
    struct Node* next;
};

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

/* DFS */
void dfs(int v, struct Node* adj[], int visited[]) {

    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {

        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited);
        }

        temp = temp->next;
    }
}

/* Main */
int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];

    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
    }

    int visited[n + 1];

    for (int i = 0; i <= n; i++)
        visited[i] = 0;

    int components = 0;

    for (int i = 1; i <= n; i++) {

        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    printf("%d", components);

    return 0;
}