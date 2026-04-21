// Day 79 - Question 1: Single Source Shortest Path using Dijkstra’s Algorithm
// Close
// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

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

/* Get minimum distance node */
int minDistance(int dist[], int visited[], int n) {

    int min = INF, index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

/* Dijkstra */
void dijkstra(int n, struct Node* adj[], int src) {

    int dist[n + 1];
    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i <= n; i++) {

        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        struct Node* temp = adj[u];

        while (temp != NULL) {

            int v = temp->data;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    /* print result */
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
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

        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(adj, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, adj, src);

    return 0;
}