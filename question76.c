#include <stdio.h>

void dfs(int v, int n, int adj[n+1][n+1], int visited[]) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n+1][n+1];
    int visited[n+1];

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, n, adj, visited);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}