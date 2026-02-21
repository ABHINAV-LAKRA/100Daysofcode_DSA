#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);

    printf("Number of subarrays with sum 0: %d\n", result);

    return 0;
}