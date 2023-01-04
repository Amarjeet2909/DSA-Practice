#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout << "Node with Value "<<value<<" has been deleted"<<endl;
    }
};

// Function to insert value at haed/ starting of the node
void insertAtHead(Node* &head, int data)
{
    // creating new node
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

// Function to insert value at tail/end of the LL
void insertAtTail(Node* &tail, int data)
{
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

// Function to insert value at specific position
void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    if(position == 1)
    {
        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < position-1)
    {
        temp = temp -> next;
        count++;
    }
    // Inserting at last
    if(temp -> next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

// Function to print Linked List
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

// Deleting head/First node of Linked List
void deletionAtHead(Node* &head, int position)
{
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
}

// Deleting last Node or any specific node
void deletionAtPosition(Node* &head, int position)
{
    Node* curr=head;
    Node* prev=NULL;
    int cnt = 1;
    while(cnt < position)
    {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

int main()
{
    Node *node1 = new Node(10);
    /* Printing manually
    cout<<node1->data<<endl;
    cout<<node1->next<<endl; */
    
    Node *head = node1;
    Node *tail = node1;

    print(head);

    // Inserting at head
    insertAtHead(head,20);
    insertAtHead(head,30);
    print(head);

    // Inserting at tail
    insertAtTail(tail, 12);
    print(head);

    // Inserting at specific position
    insertAtPosition(head, tail, 4, 200);
    print(head);

    // Deleting at head
    deletionAtHead(head, 1);
    print(head);

    // Deteting at last
    deletionAtPosition(head, 4);
    print(head);

    return 0;
}