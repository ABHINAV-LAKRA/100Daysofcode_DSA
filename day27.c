#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    if (head1 == NULL || head2 == NULL)
        return NULL;

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    while (p1 != p2) {
        if (p1 == NULL)
            p1 = head2;
        else
            p1 = p1->next;

        if (p2 == NULL)
            p2 = head1;
        else
            p2 = p2->next;
    }

    return p1; 
}

int main() {

    // Common part
    struct Node* common = createNode(40);
    common->next = createNode(50);

    // List 1
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);
    head1->next->next->next = common;

    // List 2
    struct Node* head2 = createNode(15);
    head2->next = createNode(25);
    head2->next->next = common;

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection)
        printf("Intersection at node with data: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}