// Day 70 - Question 1: Bellman-Ford Algorithm
// Close
// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

/* Edge structure */
struct Edge {
    int u, v, w;
};

/* Bellman-Ford */
void bellmanFord(int n, int m, struct Edge edges[], int src) {

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    /* Relax edges n-1 times */
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < m; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    /* Check negative cycle */
    for (int j = 0; j < m; j++) {

        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE");
            return;
        }
    }

    /* Print distances */
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
}

/* Main */
int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    bellmanFord(n, m, edges, src);

    return 0;
}