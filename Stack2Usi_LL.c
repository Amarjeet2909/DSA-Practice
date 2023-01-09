#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    printf("Stack Overflow\n");
    else{
    t->data=x;
    t->next=top;
    top=t;
    }
}

int pop(){
    struct node *t;
    int x=-1;
    if(top==NULL)
    printf("Stack is Empty\n");
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display(){
    struct node *p;
    p=top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int y,i;
    static int t;
    printf("Enter the no of values to insert:-");
    scanf("%d",&y);
    for(i=0;i<y;i++){
    printf("Enter the value\n");
    scanf("%d",&t);
    push(t);
    }
    display();
    printf("\n%d\n",pop());
    display();

    return 0;
}