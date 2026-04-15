#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char arr[MAX][LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    char names[MAX][LEN];
    int freq[MAX] = {0};
    int size = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < size; j++) {
            if (strcmp(arr[i], names[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            freq[found]++;
        } else {
            strcpy(names[size], arr[i]);
            freq[size] = 1;
            size++;
        }
    }

    int max_votes = 0;
    char ans[LEN] = "";

    for (int i = 0; i < size; i++) {
        if (freq[i] > max_votes) {
            max_votes = freq[i];
            strcpy(ans, names[i]);
        } else if (freq[i] == max_votes) {
            if (strcmp(names[i], ans) < 0) {
                strcpy(ans, names[i]);
            }
        }
    }

    printf("%s %d\n", ans, max_votes);

    return 0;
}