#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int a[n][n];
    int isIdentity = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j && a[i][j] != 1)
                isIdentity = 0;
            if(i != j && a[i][j] != 0)
                isIdentity = 0;
        }
    }
    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}