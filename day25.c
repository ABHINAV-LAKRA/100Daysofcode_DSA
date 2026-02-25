#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int value)
{
    struct Node *temp = createNode(value);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    struct Node *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
}

int countOccurrences(struct Node *head, int key)
{
    int count = 0;
    struct Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == key)
            count++;
        curr = curr->next;
    }

    return count;
}

int main()
{
    struct Node *head = NULL;
    int n, value, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter element to count: ");
    scanf("%d", &key);

    int result = countOccurrences(head, key);
    printf("Occurrences of %d = %d\n", key, result);

    return 0;
}