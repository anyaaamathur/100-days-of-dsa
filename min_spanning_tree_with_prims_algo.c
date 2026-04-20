// Day 78 - Question 1: Minimum Spanning Tree using Prim’s Algorithm

// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

/* Node */
struct Node {
    int data;
    int weight;
    struct Node* next;
};

/* Create node */
struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

/* Add edge (undirected) */
void addEdge(struct Node* adj[], int u, int v, int w) {

    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

/* Find minimum cost vertex */
int minKey(int key[], int visited[], int n) {

    int min = INF, index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }

    return index;
}

/* Prim's Algorithm */
int prim(int n, struct Node* adj[]) {

    int key[n + 1];
    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {

        int u = minKey(key, visited, n);
        visited[u] = 1;

        totalWeight += key[u];

        struct Node* temp = adj[u];

        while (temp != NULL) {

            int v = temp->data;
            int w = temp->weight;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
            }

            temp = temp->next;
        }
    }

    return totalWeight;
}

/* Main */
int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];

    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {

        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(adj, u, v, w);
    }

    printf("%d", prim(n, adj));

    return 0;
}