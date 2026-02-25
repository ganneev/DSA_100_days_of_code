#include <stdio.h>

int main() {
    int arr[100], n, pos, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {   
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter position to delete (starting from 1): ");
    scanf("%d", &pos);

    for(i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n = n - 1;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
