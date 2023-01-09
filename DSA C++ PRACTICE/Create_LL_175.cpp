#include<iostream>
using namespace std;

class node{
   public:
     int data;
     node *next;
};

int main(){
    
    int A[]= {3,5,7,10,15,56,100};

    node *head = new node;

    node *temp;
    node *last;

    head->data= A[0];
    head->next= nullptr;
    last= head;
    for(int i=1 ; i< sizeof(A)/sizeof(A[0]); i++){
        temp = new node;
        temp->data=A[i];
        temp->next= nullptr;
        last->next= temp;
        last= temp;
    }

    node *p = head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }

    return 0;
}