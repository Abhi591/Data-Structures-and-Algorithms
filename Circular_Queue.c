#include<stdio.h>
#include<stdlib.h>

struct CircularQueue{
    int size;
    int f,r;
    int * arr;
};
int isFull(struct CircularQueue * q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct CircularQueue * q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct CircularQueue * q,int val){
    if(isFull(q)){
        printf("The Queue is Full");
    }
    else{
        printf("Enqueued element: %d\n",val);
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}

int dequeue(struct CircularQueue * q){
    if(isEmpty(q)){
        printf("No element to dequeue");
        return -1;
    }
    else {
        q->f=(q->f+1)%q->size;
        return q->arr[q->f];
    }
}

int main()
{
    struct CircularQueue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int*) malloc(q.size*sizeof(int));//dynamic memory allocation
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);

    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    enqueue(&q,30);
    enqueue(&q,30);
    enqueue(&q,30);
    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }
    return 0;
}
