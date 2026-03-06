#include <stdio.h>

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int A[m][n], B[m][n], C[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter element B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf(" %d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}