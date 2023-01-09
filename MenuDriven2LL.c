#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int B[],int n)
{
    int i;
    struct node *t,*last;
    second=(struct node*)malloc(sizeof(struct node));
    second->data=B[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct node *p)
{
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int count(struct node *p)
{
    int a=0;
    while(p!=NULL){
        a++;
        p=p->next;
    }
    return a;
}

void Insert(struct node *p,int index,int x)
{
    int i;
    struct node *t;
    if(index < 0 || index > count(p))
    return;
    t=(struct  node*)malloc(sizeof(struct node));
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++)
            p=p->next;
            t->next=p->next;
            p->next=t;
    }
}

void InsertLast(int x) {
struct node *t, *last;
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->next=NULL;
if(first==NULL) {
first=t;
last=t;
} 
else {
last=first;
while(last->next)
last=last->next;
last->next=t;
last=t;
}
}

void SortedInsert(struct node *p,int x)
{
    struct node *t,*q=NULL;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
    first=t;
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
        t->next=q->next;
        q->next=t;
        }
    }
}

int Delete(struct node *p,int index)
{
    struct node *t=NULL;
    int x=-1;
    if(index<1 || index>count(p))
    return x;
    if(index==1){
        t=first;
        x=first->data;
        first=first->next;
        free(t);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
        t=p;
        p=p->next;
        }
        t->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int IsSorted(struct node *p)
{
    int x=-1;
    while(p!=0){
        if(p->data<x)
        return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void RemoveDuplicate(struct node *p)
{
    struct node *t=p->next;
    while(t!=NULL){
        if(p->data!=t->data){
            p=t;
            t=t->next;
        }
        else{
            p->next=t->next;
            free(t);
            t=p->next;
        }
    }
}

void ReverseByArr(int A[],struct node *p)
{
    int i=0;
    while(p!=NULL){
         A[i]=p->data;
         p=p->next;
         i++;
    }
    p=first;
    i--;
    while(p!=NULL){
        p->data=A[i--];
        p=p->next;
    }
}

void ReverseByLink(int A[],struct node *p)
{
    struct node*t=NULL,*q=NULL;
    while(p!=NULL){
        t=q;
        q=p;
        p=p->next;
        q->next=t;
    }
    first=q;
}

void ReverseByRecursion(struct node *t,struct node *p)
{
    if(p)
    {
    ReverseByRecursion(p,p->next);
    p->next=t;
    }
    else
    first=t;
}

void Concatenate(struct node *p,struct node *q)
{
    third=p;
    while(p->next!=NULL)
        p=p->next;
        p->next=q;
}

void merge(struct node *p,struct node *q)
{
    struct node *last;
    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
        if(p)
        last->next=p;
        if(q)
        last->next=q;
    }
}

int IsLoop(struct node *f)
{
    struct node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q!=NULL?q->next:q;
    }while(p && q && p!=q);
    if(p==q)
    return 1;
    else
    return 0;
}
int main(){
    struct node *t1,*t2;
    int A[10]={25,65,78,48,100,41,454,74,54,87};
    create(A,10);
    t1=first->next->next->next;
    t2=first->next->next->next->next->next->next->next->next->next;
    t2->next=t1;
    printf("\n%d ",IsLoop(first));
    return 0;
}

/*int main()
{   
    int A[]={5,12,45,78,52,78,85,90,95,102};
    int B[]={2,4,7,8,9,10,15,20,25,30};
    //int C[]={5,7,7,7,9,9,10};
    //create(C,7);
    create(A,10);
    create2(B,10);
    //InsertLast(10);
    //InsertLast(100);
    //InsertLast(200);
    //InsertLast(500);
    //SortedInsert(first,87);
    //Delete(first,13);
    //RemoveDuplicate(first);
    //ReverseByArr(B,first);
    //ReverseByLink(A,first);
    //ReverseByRecursion(NULL,first);
    //Concatenate(second,first);
    merge(first,second);
    Display(third);
    //printf("%d ",IsSorted(first));
    return 0;    
}*/