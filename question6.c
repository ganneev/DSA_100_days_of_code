#include <stdio.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    if(n <= 0) return 0;
    int arr[n];

    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("%d ", arr[0]);

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}