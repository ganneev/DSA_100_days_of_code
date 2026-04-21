#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[100];
int visited[100];
int stack[100];
int top = -1;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while(temp) {
        if(!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }

    stack[++top] = v;
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

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    while(top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}