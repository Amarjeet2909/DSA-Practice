#include<stdio.h>
#include<stdlib.h>

   struct Node{
       int data;
       struct Node *next;
   };
   void DisplayLL(struct Node *ptr)
   {
       while(ptr!=NULL){
       printf("Element is: %d\n",ptr->data);
       ptr=ptr->next;
       }
   }

int main(){
   struct Node *first;
   struct Node *second;
   struct Node *third;
   struct Node *four;
   //Allocating memory for linked list in heap
   first= (struct Node*)malloc(sizeof(struct Node));
   second=  (struct Node*)malloc(sizeof(struct Node));
   third=  (struct Node*)malloc(sizeof(struct Node));
   four=  (struct Node*)malloc(sizeof(struct Node));
   
   //Linking First and second nodes
   first->data=12;
   first->next=second;
   //Linking second and third nodes
   second->data=45;
   second->next=third;
   //Linking third and fourth nodes
   third->data=100;
   third->next=four;
   //Terminating the last node
   four->data=15;
   four->next=NULL;
   //Displaying the LL
   DisplayLL(first);
   return 0;
}