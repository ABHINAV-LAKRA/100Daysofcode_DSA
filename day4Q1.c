#include <stdio.h>

void reverseArray(int arr[], int n)
{
    int start = 0, end = n - 1, temp;

    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int i;

    reverseArray(arr, n);

    printf("Reversed array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
