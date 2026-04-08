#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if(rear == MAX - 1)
        return;
    queue[++rear] = x;
}

void display() {
    for(int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if(i != rear) printf(" ");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    return 0;
}