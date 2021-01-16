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
};

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
};

struct Node * deleteAtIndex(struct Node * head,int index){
    struct Node * p= head;
    struct Node * q = head->next;
    for (int i=0;i < index-1; i++){
        p=p->next;
        q=q->next;
    }

    p->next=q->next;
    free(q);
    return head;
}

struct Node * deleteAtLast(struct Node * head){
    struct Node * ptr=head;
    struct Node * p=head->next;
    while(p->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    free(p);
    ptr->next=NULL;
    return head;
};

struct Node * deleteAtVal(struct Node * head, int val){
    struct Node * ptr=head;
    struct Node * p= head->next;
    while(p->data!=val && p->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    if(p->data==val){
        ptr->next=p->next;
        free(p);
    }
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

    printf("Linked List before Deletion\n");
    linkedlistTraversal(head);

    // head=deleteFirst(head);
    // head=deleteAtIndex(head,2);
    // head=deleteAtLast(head);
    head=deleteAtVal(head,41);
    printf("Linked List after Deletion\n");
    linkedlistTraversal(head);
    return 0;
}
