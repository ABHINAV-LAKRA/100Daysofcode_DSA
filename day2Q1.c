#include <stdio.h>

int main() {
    int n, pos;
    int a[50];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    for(int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;

    printf("Array after deletion:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}