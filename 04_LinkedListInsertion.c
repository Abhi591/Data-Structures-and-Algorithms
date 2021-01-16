#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
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
// CASE 1
struct Node * InsertAtFirst(struct Node *head,int data){
    struct Node * ptr=(struct Node *) malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
};
// CASE 2
struct Node * InsertAtIndex(struct Node *head,int data,int index){
    struct Node * ptr=(struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
};
// CASE 3
struct Node * InsertAtEnd(struct Node *head,int data){
    struct Node * ptr=(struct Node *) malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    return head;
};
// CASE 4
struct Node * InsertAfterNode(struct Node *head,struct Node *prevNode,int data){
    struct Node * ptr=(struct Node *) malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // allocate memory for Nodes in LinkedList in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // terminate the third node
    third->data = 41;
    third->next = fourth;

    // terminate the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked List before Insertion\n");
    linkedlistTraversal(head);      
    // head=InsertAtFirst(head,56);
    // head=InsertAtIndex(head,56,1);
    // head=InsertAtEnd(head,56);
    head=InsertAfterNode(head,second,45);
    printf("Linked list After Insertion");
    linkedlistTraversal(head);
    return 0;
}

