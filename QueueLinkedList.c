#include<stdio.h>
#include<stdlib.h>

struct Node * f=NULL;
struct Node * r=NULL;

struct Node{
    int data;
    struct Node * next;
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

int isFull(struct Node * ptr){
    struct Node * p=(struct Node *) malloc(sizeof(struct Node));
    if(p==NULL){
        printf("Memory FULL");
        return 1;
    }
    return 0;
}

int isEmpty(struct Node * f){
    if(f==NULL){
        return 1;
    }
    return 0;
}

void enqueue(int val){
    struct Node * p=(struct Node *) malloc(sizeof(struct Node));
    if(isFull(p)){
        printf("Cannot Enqueue element: %d\n",val);
    }
    else{
        p->data=val;
        p->next=NULL;
        if(isEmpty(f)){
            f=r=p;
        }
        else{
            r->next=p;
            r=p; 
        }
    }
}

int dequeue(){
    if(isEmpty(f)){
        printf("Cannot dequeue");
        return -1;
    }
    struct Node * p=(f);
    f=f->next;
    int val=p->data;
    free(p);
    return val;
}

int main()
{
    if(isEmpty(f)){
        printf("Queue is Empty\n");
    }
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    linkedlistTraversal(f);
    int data;
    data=dequeue();
    data=dequeue();
    printf("Dequeued data: %d\n",data);
    linkedlistTraversal(f);
    return 0;
}
