#include <stdio.h>

int isPossible(int arr[], int n, int m, int mid)
{
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > mid) return 0;

        if(pages + arr[i] > mid)
        {
            students++;
            pages = arr[i];

            if(students > m) return 0;
        }
        else
        {
            pages += arr[i];
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m)
{
    if(n < m) return -1;

    int low = 0, high = 0, ans = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > low) low = arr[i];
        high += arr[i];
    }

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &m);

    int result = allocateBooks(arr, n, m);

    printf("%d", result);

    return 0;
}