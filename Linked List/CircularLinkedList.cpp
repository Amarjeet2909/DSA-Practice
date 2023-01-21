#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor function
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    // destructor function
    ~Node()
    {
        int value = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Node with value "<<value<<" has been deleted"<<endl;
    }
};                                                                                                                

void print(Node* tail)
{
    Node* temp = tail;

    if(tail == NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    do {
        cout<< tail -> data <<" ";
        tail = tail -> next;
    } while(tail != temp);
    cout<<endl;
}

void insert(Node* &tail, int element, int data)
{
    if(tail == NULL)
    {
        // linked list is empty
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else
    {
        Node* curr = tail;
        while(curr -> data != element)
        {
            curr = curr -> next;
        }
        Node* NodetoInsert = new Node(data);
        NodetoInsert -> next = curr -> next;
        curr -> next = NodetoInsert;     
    }
}

void deleteNode(Node* &tail, int value)
{
    if(tail == NULL)
    {
        cout<<"List is empty !!";
    }
    else
    {
        Node* curr = tail;
        Node* prevNode = NULL;

        while(curr -> data != value)
        {
            prevNode = curr;
            curr = curr -> next;
        }
        prevNode -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main()
{
    Node* tail = NULL;
    insert(tail,0,100);
    print(tail);
    insert(tail,100,200);
    print(tail);
    insert(tail,200,300);
    print(tail);
    insert(tail,100,44);
    print(tail);
    deleteNode(tail,300);
    print(tail);
    insert(tail,200,21);
    print(tail);
    return 0;
}