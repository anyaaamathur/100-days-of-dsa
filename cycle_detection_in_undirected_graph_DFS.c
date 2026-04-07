// Day 65 - Question 1: Cycle Detection in Undirected Graph (DFS)

// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <stdio.h>
#include <stdlib.h>

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

/* DFS cycle check */
int dfs(int v, int parent, struct Node* adj[], int visited[]) {

    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {

        int neigh = temp->data;

        if (!visited[neigh]) {
            if (dfs(neigh, v, adj, visited))
                return 1;
        }
        else if (neigh != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
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

    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}