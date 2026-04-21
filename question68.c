#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[100];
int indegree[100];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    indegree[v]++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int queue[100];
    int front = 0, rear = 0;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while(front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];
        while(temp) {
            indegree[temp->vertex]--;

            if(indegree[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }

    if(count != n) {
        printf("\nCycle detected! Topological sort not possible.");
    }

    return 0;
}