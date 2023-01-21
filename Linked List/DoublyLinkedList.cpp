#include <bits/stdc++.h>
using namespace std;

// Node Structure ********************************************************************************************************************
class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int data)
    {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this -> data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Node with value "<<value<<" has been deleted"<<endl;
    }
};
// *********************************************************************************************************************

// Traversing/ Printing LinkedList
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

// Insert at Head
void insertAtHead(Node* &head, Node* &tail, int data)
{
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

// Insert at Tail
void insertAtTail(Node* &head, Node* &tail, int data)
{
    if(tail == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(data);
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

// Insert at particular position
void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    if(position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    else
    {
        Node* temp = head;
        int countForPosition = 1;
        while(countForPosition < position-1)
        {
            temp = temp -> next;
            countForPosition++;
        }

        // Checking if position is tail position
        if(temp -> next == NULL)
        {
            insertAtTail(head, tail, data);
            return;
        }

        Node* nodeToInsert = new Node(data);
        nodeToInsert -> prev = temp;
        nodeToInsert -> next = temp -> next;
        temp -> next -> prev = nodeToInsert;
        temp -> next = nodeToInsert;
    }
}

void deleteNode(Node* &head, int position)
{
    if(position == 1)
    {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting a head
    insertAtHead(head, tail,100);
    insertAtHead(head, tail,200);
    print(head);
    
    // Inserting at tail
    insertAtTail(head, tail, 300);
    print(head);

    // Inserting at particular position
    insertAtPosition(head, tail, 4, 500);
    print(head);

    // Deleting the node
    deleteNode(head, 4);
    print(head);

    return 0;
}