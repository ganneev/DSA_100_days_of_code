#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Insert
void insert(int x) {
    if(size == MAX) return;

    int i = size;
    heap[size++] = x;

    // heapify up
    while(i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract Min
int extractMin() {
    if(size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int i = 0;

    // heapify down
    while(1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return min;
}

// Peek
int peek() {
    if(size == 0) return -1;
    return heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        char op[20];
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
        else if(strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}