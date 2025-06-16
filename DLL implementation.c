#include<stdio.h>
#include<stdlib.h>
typedef struct dll {
   int data;
   struct dll *prev;
   struct dll* next;
}Node;

Node* create(int data)
{
    Node* newNode=(Node *)malloc(sizeof(Node));
    
    if(!newNode)
    {
        printf("Memory Allocation failed!");
        exit(1);
    }
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insert(Node** head,int data)
{
    Node* node=create(data);
    if(*head==NULL)
    {
        *head=node;
    }
    
    else
    {
        (*head)->prev=node;
        node->next=*head;
        *head=node;
    }
}
int main()
{
    Node* head=NULL;
    
    int data1=70;
    insert(&head,data1);
    
    int data2=80;
    insert(&head,data2);
    
    int data3=90;
    insert(&head,data3);
    
    int data4=100;
    insert(&head,data4);
    
    printf("NULL<->");
    while(head!=NULL)
    {
        printf("%d<->",head->data);
        head=head->next;
    }
    printf("NULL");
    
    return 0;
}