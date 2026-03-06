#include <stdio.h>

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int a[m][n];
    int sum = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < m && i < n; i++) {
        sum += a[i][i];
    }
    printf("%d", sum);
    return 0;
}