#include <stdio.h>

int main()
{
    int log1[50], log2[50], merged[100];
    int n1, n2;
    int i = 0, j = 0, k = 0;

    printf("Enter number of entries in first log: ");
    scanf("%d", &n1);

    printf("Enter arrival times for first log:\n");
    for(i = 0; i < n1; i++)
        scanf("%d", &log1[i]);

    printf("Enter number of entries in second log: ");
    scanf("%d", &n2);

    printf("Enter arrival times for second log:\n");
    for(i = 0; i < n2; i++)
        scanf("%d", &log2[i]);

    i = 0;
    j = 0;

    /* merge both logs */
    while(i < n1 && j < n2)
    {
        if(log1[i] <= log2[j])
        {
            merged[k] = log1[i];
            i++;
        }
        else
        {
            merged[k] = log2[j];
            j++;
        }
        k++;
    }

    /* copy remaining elements */
    while(i < n1)
    {
        merged[k] = log1[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        merged[k] = log2[j];
        j++;
        k++;
    }

    printf("\nMerged chronological log:\n");
    for(i = 0; i < k; i++)
        printf("%d ", merged[i]);

    return 0;
}
