#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct stack *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow Cannot push %d to the stack\n", data);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

char Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot Pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *infixToPostfix(char *infix)
{
    struct stack * ptr= (struct stack *) malloc(sizeof(struct stack));
    ptr->size=100;
    ptr->top=-1;
    ptr->arr=(char *)malloc(ptr->size * sizeof(char));
    char * postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(ptr)))
            {
                Push(ptr, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = Pop(ptr);
                j++;
            }
        }
    }
    while (!isEmpty(ptr))
    {
        postfix[j] = Pop(ptr);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y*z";
    printf("Postfix is %s", infixToPostfix(infix));
    return 0;
}