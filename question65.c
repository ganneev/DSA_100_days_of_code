#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[100];
int visited[100];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int dfs(int v, int parent) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while(temp) {
        int u = temp->vertex;

        if(!visited[u]) {
            if(dfs(u, v))
                return 1;
        }
        else if(u != parent) {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int hasCycle = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}