#include <stdio.h>

int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime) return 0;

        if (sum + arr[i] > maxTime) {
            painters++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int maxVal = 0, total = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > maxVal) maxVal = arr[i];
        total += arr[i];
    }

    int left = maxVal, right = total, ans = total;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}