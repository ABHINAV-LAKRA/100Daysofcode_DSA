#include <stdio.h>

int main() {
    int n;
    int a[10][10];
    int flag = 1;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("\nEnter elements of matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Checking symmetry
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1)
        printf("\nMatrix is Symmetric");
    else
        printf("\nMatrix is Not Symmetric");

    return 0;
}
