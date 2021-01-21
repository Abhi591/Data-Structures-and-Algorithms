#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f,r;
    int * arr;
};
int isFull(struct Queue * q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Queue * q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct Queue * q,int val){
    if(isFull(q)){
        printf("The Queue is Full");
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=val;
    }
}

int dequeue(struct Queue * q){
    if(isEmpty(q)){
        printf("No element to dequeue");
        return -1;
    }
    else {
        q->f++;
        return q->arr[q->f];
    }
}

int main()
{
    struct Queue q;
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int*) malloc(q.size*sizeof(int));//dynamic memory allocation
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);

    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    if(isEmpty(&q)){
        printf("Queue is Empty");
    }
    return 0;
}
