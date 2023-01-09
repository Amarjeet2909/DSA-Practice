#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

struct node *root= NULL;

void TreeCreate()
{
    struct node *p, *t;
    int x;
    struct queue q;
    create(&q,100);

    printf("Enter root value: \n");
    scanf("%d",&x);
    root= (struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("Enter Left child of %d \n",p->data);
        scanf("%d",&x);
        if(x!=-1){
        t= (struct node *)malloc(sizeof(struct node));
        }
    }
}