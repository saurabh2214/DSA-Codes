#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data=x;
        prev=next=NULL;
    }
};

Node *insertBegin(Node *head ,int x)//Inserting from Begining of the doubly Link List
{
    Node *temp=new Node(x);
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}

Node *insertEnd(Node *head, int x)//Inserting from End of the doubly Link List
{
    Node *temp=new Node(x);
    if(head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return head;
}

Node *delBegin(Node *head)//Deleting from Begining of the doubly Link List
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;
}

Node *delEnd(Node *head)//Deleting from End of the doubly Link List
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->prev->next=NULL;
    delete curr;
    return head;
    
}

void rPrint(Node *head)//Print Link List
{
    if(head == NULL)
        return;
    cout<<(head->data)<<" ";
    rPrint(head->next);
}

int main()
{
    Node *head;
    head = insertBegin(head,30);
    head = insertBegin(head,20);
    head = insertBegin(head,10);
    rPrint(head);
    cout<<endl;
    
    head = insertEnd(head,40);
    head = insertEnd(head,50);
    head = insertEnd(head,60);
    rPrint(head);
    cout<<endl;
    
    head = delBegin(head);
    head = delBegin(head);
    rPrint(head);
    cout<<endl;
    
    head = delEnd(head);
    head = delEnd(head);
    rPrint(head);
    cout<<endl;

    return 0;
}

