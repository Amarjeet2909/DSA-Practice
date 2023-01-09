#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    first= (struct node*)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t= (struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int count(struct node *p)
{
    int count=0;
    while(p!=NULL){
       count++;
       p=p->next;
    }
    return count;
}
//Recursive fun for counting nodes
int Rcount(struct node *p)
{
    int count=0;
    if(p==0){
        return 0;
    }
    else{
        return Rcount(p->next)+1;
    }
}

int add(struct node *p)
{
    int addition=0;
    while(p!=0){
        addition=addition+p->data;
        p=p->next;
    }
    return addition;
}

int Radd(struct node *p)
{
    if(p==0)
    return 0;
    else
    return Radd(p->next)+p->data;
}

int maximum(struct node *p)
{
    int max=0;
    while(p!=0){
        if(p->data>max)
        max=p->data;
        p=p->next;
    }
    return max;
}

struct node* search(struct node *p,int key)
{
    while(p!=NULL){
         if(p->data==key)
         return p;
         p=p->next;
     }
     return NULL;
}

struct node* ImprovedSearch(struct node *p,int key)
{   
    struct node *t=NULL;
    while(p!=0){
        if(p->data==key){
            t->next=p;
            p->next=first;
            first=p;
            return p;
        }
          t=p;
          p=p->next;
    }
    return NULL;
}

int main(){
    int res1,res2,add1,add2;
    int max1;
    struct node *key1,*key2;
    int A[]={2,5,7,8,9,15,45,78,77,89};
    create(A,10);
    add1=  add(first);
    res1= count(first);
    res2= Rcount(first);
    add2= Radd(first);
    max1= maximum(first);
    key1= search(first,77);
    key2= ImprovedSearch(first,77);
    printf("Total no of nodes by normal function is: %d",res1);
    printf("\nTotal no of nodes by recursive function is: %d",res2);
    printf("\nAddition by normal fun is: %d",add1);
    printf("\nAddition by recursive fun is: %d",add2);
    printf("\nMaximum number in node is:%d",max1);
    printf("\naddress of key is : %d",key1);
    printf("\naddress of key is : %d",key2);
    return 0;
}