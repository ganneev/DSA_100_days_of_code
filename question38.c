#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void push_front(int x) {
    if(isFull()) return;

    if(isEmpty()) {
        front = rear = 0;
    } else if(front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = x;
}

void push_back(int x) {
    if(isFull()) return;

    if(isEmpty()) {
        front = rear = 0;
    } else if(rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

void pop_front() {
    if(isEmpty()) return;

    if(front == rear) {
        front = rear = -1;
    } else if(front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if(isEmpty()) return;

    if(front == rear) {
        front = rear = -1;
    } else if(rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

int getFront() {
    if(isEmpty()) return -1;
    return deque[front];
}

int getBack() {
    if(isEmpty()) return -1;
    return deque[rear];
}

int getSize() {
    if(isEmpty()) return 0;
    if(rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

void display() {
    if(isEmpty()) return;

    int i = front;
    while(1) {
        printf("%d", deque[i]);
        if(i == rear) break;
        printf(" ");
        i = (i + 1) % MAX;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        char op[20];
        scanf("%s", op);

        if(strcmp(op, "push_front") == 0) {
            int x; scanf("%d", &x);
            push_front(x);
        }
        else if(strcmp(op, "push_back") == 0) {
            int x; scanf("%d", &x);
            push_back(x);
        }
        else if(strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if(strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if(strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        }
        else if(strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        }
        else if(strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else if(strcmp(op, "size") == 0) {
            printf("%d\n", getSize());
        }
    }

    display();

    return 0;
}