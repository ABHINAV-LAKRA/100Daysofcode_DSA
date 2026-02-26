#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* insertEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    struct Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void traverseForward(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void traverseBackward(struct Node *head)
{
    if(head == NULL)
        return;

    struct Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    struct Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    printf("Forward: ");
    traverseForward(head);

    printf("\nBackward: ");
    traverseBackward(head);

    return 0;
}