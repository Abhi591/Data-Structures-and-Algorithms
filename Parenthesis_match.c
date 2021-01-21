#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
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

void Push(struct stack * ptr,char data){
    if(isFull(ptr))
    {
        printf("Stack Overflow Cannot push %d to the stack\n",data);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}

char Pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot Pop from the stack\n");
        return -1;
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char * exp){
    // create and initialize the stack
    struct stack * ptr;
    ptr->size=100;     //assuming that my expression will not be greater tha 100
    ptr->top=-1;
    ptr->arr=(char *)malloc(ptr->size*sizeof(char));
    
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='('){
            Push(ptr,'(');
        }
        else if(exp[i]==')'){
            if(isEmpty(ptr)){
                return 0;
            }
            Pop(ptr);
        }
    }
    if(isEmpty(ptr)){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    char * exp="(8)*(9)";
    if(parenthesisMatch(exp)){
        printf("The Parenthesis is matching");
    }
    else{
        printf("The Parenthesis is not matching");
    }
    return 0;
}