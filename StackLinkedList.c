#include<stdio.h>
#include<stdlib.h>

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

int isEmpty(struct Node * ptr){
    if(ptr==NULL){
        printf("Stack is Empty\n");
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node * ptr){
    struct Node * p=(struct Node *)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node * Push(struct Node * ptr,int val){
    if(isFull(ptr)){
        printf("stack overflow cannot insert %d\n",val);
    }
    else{
        struct Node * p=(struct Node *)malloc(sizeof(struct Node));
        p->data=val;
        p->next=ptr;
        ptr=p;
        return ptr;
    }
}

int pop(struct Node ** ptr){
    if(isEmpty(*ptr)){
        printf("Stack Underflow cannot pop an element\n");
        return -1;
    }
    else{
        struct Node * p=*ptr;
        *ptr=(*ptr)->next;
        int x=p->data;
        free(p);
        return x;
    }
}

int peek(struct Node * ptr,int pos){
    struct Node * p=ptr;
    int i=0;
    while(i<pos-1 && p!=NULL){
        p=p->next;
        i++;
    }
    if(p!=NULL){
        return p->data;
    }
    else{
        return -1;
    }
}

int stacktop(struct Node * ptr){
    if(isEmpty(ptr)){
        return -1;
    }
    else{
        return ptr->data;
    }
}

int stackbottom(struct Node * ptr){
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node * top=NULL;
    //stack is empty when top==NULL
    //stack is full when the heap memory is exhausted
    // (whenever we'll try to add new element ptr will become NULL )
    // we can always set a custom size

    top=Push(top,10);  //Push operation
    top=Push(top,20);
    top=Push(top,30);
    top=Push(top,40);
    printf("Stack After Pushing elements\n");
    linkedlistTraversal(top);

    int element=pop(&top); //pop operation
    printf("Popped element is %d\n",element);
    linkedlistTraversal(top);

    printf("Element at position %d is %d\n",2,peek(top,2));
    printf("Top element of stack is %d\n",stacktop(top));
    printf("Bottom element of stack is %d\n",stackbottom(top));
    return 0;
}