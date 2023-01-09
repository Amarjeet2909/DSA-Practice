#include <iostream>
using namespace std;

class node{
   public:
      int data;
      node *next; 
};

class stack{
   private:
     node *top;
   public:
     stack();
     ~stack();
     void push(int x);
     int pop();
     int peek(int index);
     int isempty();
     int isfull();
     int stacktop();   
};

stack::stack(){
     top=nullptr;
}

stack::~stack(){
     node *p=top;
     while(top){
       top=top->next;
       delete p;
       p=top;
     }
}

void stack::push(int x){
     node *t= new node;
     if(t== nullptr){
       cout << "stack overflow" <<endl;
     }
     else{
       t->data=x;
       t->next=top;
       top=t;
     }
} 

int stack::pop(){
    node *p;
    int x=-1;
    if(top==nullptr)
    cout << "stack underflow" <<endl;
    else{
      p=top;
      x=top->data;
      top=top->next;
      delete p;
    }
    return x;
}

int stack::isfull(){
    node *t= new node;
    int r=t ? 1 : 0;
    delete t;
    return r;
}

int stack::isempty(){
    return top ? 0 : 1;
}

int stack::stacktop(){
    if(top){
    return top->data;
    }
    return -1;
}

int stack::peek(int index){
    if(isempty())
    return -1;
    else{
      node *p=top;

      for(int i=0; p!=nullptr && i<index-1; i++)
      p= p->next;

      if(p!=nullptr)
      return p->data;
      else
      return -1;
    }
}
int main(){
    
        int A[] = {1, 3, 5, 7, 9};
 
    stack stk;
 
    // Populate stack
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.push(A[i]);
    }
 
    cout << "Stack peek at 3rd: " << stk.peek(3) << endl;
    cout << "Stack peek at 10th: " << stk.peek(10) << endl;
    cout << "Stack top: " << stk.stacktop() << endl;
    cout << "Stack full: " << stk.isfull() << endl;
    cout << "Stack empty: " << stk.isempty() << endl;
 
    // Pop out elements from stack
    cout << "Popped: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
 
    // Underflow
    cout << stk.pop() << endl;

    return 0;
}