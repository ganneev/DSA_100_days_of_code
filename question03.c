#include <stdio.h>

int main() {
    int arr[100], n, k;
    int i;
    int comparisons = 0;
    int found = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;   
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Not Found\n");
    }
    printf("Comparisons = %d", comparisons);
    return 0;
}
