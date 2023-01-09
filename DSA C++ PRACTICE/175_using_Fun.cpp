#include <iostream>
using namespace std;

class node {
   public:
    int data;
    node *next;
};
void display(node *p);
void create(int A[], int n){
    node *temp, *last;
    node *head= new node;
    head->data= A[0];
    head->next= nullptr;
    last= head;
    for(int i=1; i<n; i++){
        temp= new node;
        temp->data= A[i];
        temp->next= nullptr;
        last->next= temp;
        last= temp;
    }
    display(head);
}

void display(node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    int A[]= {10,20,30,40,50,60,70,80,90,100};
    create(A,10);
    return 0;
}