#include <stdio.h>
#include <stdlib.h>

#define SIZE 200001   // to handle negative numbers

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int n = 4;

    int hash[SIZE];
    
    // Initialize hash with -1
    for (int i = 0; i < SIZE; i++)
        hash[i] = -1;

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        int index = complement + 100000;

        if (hash[index] != -1) {
            printf("[%d, %d]\n", hash[index], i);
            return 0;
        }

        // Store index of current element
        hash[nums[i] + 100000] = i;
    }

    return 0;
}
