#include <stdio.h>

int integerSqrt(int n) {
    if (n < 2) return n;

    int low = 0, high = n, mid;
    int ans = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if ((long long)mid * mid == n) {
            return mid;
        }
        else if ((long long)mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Integer square root: %d\n", integerSqrt(n));
    return 0;
}