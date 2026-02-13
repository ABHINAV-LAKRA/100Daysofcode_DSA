#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[100][100];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    printf("Spiral Order Traversal:\n");

    while(top <= bottom && left <= right) {

        // Step 1: Left to Right
        for(int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Step 2: Top to Bottom
        for(int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Step 3: Right to Left
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Step 4: Bottom to Top
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}
