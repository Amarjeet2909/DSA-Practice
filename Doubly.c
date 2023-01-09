#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void create(int A[],int n)
{
    struct node *t,*last;
    int i;

    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct node *p)
{
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int Length(struct node *p)
{
    int len=0;
    while(p){
       len++;
       p=p->next;
    }
    return len;
}

void Insert(struct node *p,int index,int x)
{
    struct node *t;
    int i;
    if(index<0 || index>Length(first))
    return;
    if(index==0)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(i=1;i<index-1;i++)
        p=p->next;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)
        p->next->prev=t;
        p->next=t;
    }
}

int Delete(struct node *p, int index)
{
    struct node *q;
    int x=-1,i;
    if(index<0 || index>Length(p))
    return -1;

    if(index==1)
    {
        first=first->next;
        if(first)
        first->prev=NULL;
        x=p->data;
        free(p);
    }
    else 
    {
        for(i=0;i<index-1;i++)
        p=p->next;
        p->prev->next=p->next;
        if(p->next)
        p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

void Reverse(struct node *p)
{
    struct node *temp;
    while(p!=NULL){
          temp=p->next;
          p->next=p->prev;
          p->prev=temp;
          p=p->prev;
          if(p!=NULL && p->next==NULL)
          first=p;
    }
}
int main(){
    int A[]={12,54,78,98,100,144};
    create(A,6);
    Reverse(first);
    //Delete(first,6);
    //Insert(first,7,187);
    //printf("%d\n",Length(first));
    Display(first);
    return 0;
}