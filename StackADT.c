#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr ){
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack* ptr ){
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct stack * ptr,int data){
    if(isFull(ptr))
    {
        printf("Stack Overflow Cannot push %d to the stack\n",data);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

int Pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot Pop from the stack\n");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack * ptr,int i){
    if(ptr->top-i+1 < 0){
        printf("Not a vaid position\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}

int stacktop(struct stack * ptr){
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack * ptr){
    return ptr->arr[0];
}

int main()
{
    
    struct stack *s=(struct stack *) malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *) malloc(s->size*sizeof(int));

    printf("Before Pushing, Full: %d\n",isFull(s));
    printf("Before Pushing, Empty: %d\n",isEmpty(s));

    Push(s,1);
    Push(s,2);
    Push(s,3);
    Push(s,4);
    Push(s,5);
    Push(s,6);
    Push(s,7);
    Push(s,8);
    Push(s,9);
    Push(s,10); // --> pushed 10 values
    Push(s,11); // stack overflow since the size of stack is 10
    
    printf("After Pushing, Full : %d\n",isFull(s));
    printf("After Pushing, Empty : %d\n",isEmpty(s));
    
    // printf("Popped %d from the stack\n",Pop(s));

    printf("Value at %d is %d\n",12,peek(s,12));
    printf("Element at top is : %d\n",stacktop(s));
    printf("Element at bottom is : %d",stackbottom(s));
    return 0;
}
