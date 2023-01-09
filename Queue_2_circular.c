#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct queue *q, int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q= (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q, int x)
{
    if((q->rear+1)%q->size==q->front)
    printf("Queue id Full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    printf("Queue is Empty!\n");
    else
    {
       q->front=(q->front+1)%q->size;
       x=q->Q[q->front];
    }
    return x;
}

void display(struct queue q)
{
    int i= q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i= (i+1) % q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

int main(){
    
    struct queue q;
    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);

    display(q);
    printf("%d ",dequeue(&q));

    return 0;
}