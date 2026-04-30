#include <stdio.h>

int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;

        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

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

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}