// Day 69 - Question 1: Dijkstraâ€™s Algorithm (Shortest Path)

// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

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

/* Find min distance node */
int minDistance(int dist[], int visited[], int n) {

    int min = INF, minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

/* Dijkstra */
void dijkstra(struct Node* adj[], int n, int src) {

    int dist[n], visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {

        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        struct Node* temp = adj[u];

        while (temp != NULL) {

            int v = temp->data;
            int w = temp->weight;

            if (!visited[v] && dist[u] != INF &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    /* print result */
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
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

        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(adj, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(adj, n, src);

    return 0;
}