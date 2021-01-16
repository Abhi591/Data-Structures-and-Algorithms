#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node * head){
    struct Node * ptr=head;
    do{
        printf("Element is :  %d\n",ptr->data);
        ptr=ptr->next;

    }while(ptr!=head);
}

struct Node * insertionAtFirst(struct Node * head,int data){
    struct Node * ptr=(struct Node *) malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p =head;
    while(p->next!=head){
        p=p->next;;
    }
    p->next=ptr;
    ptr->next=head;
    return ptr;
};

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
    head->next = second;

    // link second and third nodes
    second->data = 3;
    second->next = third;

    // terminate the third node
    third->data = 6;
    third->next = fourth;

    // terminate the fourth node
    fourth->data = 1;
    fourth->next = head;

    printf("Before Insertion\n");
    linkedlistTraversal(head);
    
    head=insertionAtFirst(head,50);
    printf("Circular Linked LIst after Insertion\n");
    linkedlistTraversal(head);
    return 0;
}
