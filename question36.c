#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

void enqueue(int x) {
    if(size == MAX) return;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    size++;
}

void dequeue() {
    if(size == 0) return;
    front = (front + 1) % MAX;
    size--;
}

void display() {
    int i = front;
    for(int count = 0; count < size; count++) {
        printf("%d", queue[i]);
        if(count != size - 1) printf(" ");
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}