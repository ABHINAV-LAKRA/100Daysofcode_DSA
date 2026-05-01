#include <stdio.h>

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + boards[i] > maxTime) {
            painters++;
            sum = boards[i];
        } else {
            sum += boards[i];
        }
    }

    return painters <= k;
}

int minTime(int boards[], int n, int k) {
    int max = boards[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > max) max = boards[i];
        sum += boards[i];
    }

    int low = max, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n = 4, k = 2;
    int boards[] = {10, 20, 30, 40};

    printf("%d\n", minTime(boards, n, k));

    return 0;
}