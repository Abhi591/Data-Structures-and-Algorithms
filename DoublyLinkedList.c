#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // allocate memory for nodes in LinkedList in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 4;
    head->prev=NULL;
    head->next = second;

    // link second and third nodes
    second->data = 3;
    second->prev=head;
    second->next = third;

    // terminate the third node
    third->data = 6;
    third->prev=second;
    third->next = fourth;

    // terminate the fourth node
    fourth->data = 1;
    fourth->prev=third;
    fourth->next = NULL;

    linkedlistTraversal(head);
}
