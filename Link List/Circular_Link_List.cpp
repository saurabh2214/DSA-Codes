#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node (int d)
    {
        data = d;
        next = NULL;
    }
};

Node* InsertBegin(Node* head,int x)//Inserting at begning of Circular Link List 
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int t=temp->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
}

Node* insertEnd(Node* head,int x)//Inserting at End of Circular Link List
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int t=temp->data;
        temp->data=head->data;
        head->data=t;
        return temp;
    }
}

Node* delHead(Node *head)//Deleteing at First of Circular Link List
{
    if(head==NULL)
        return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node* temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}

Node* delKth(Node* head,int k)//Deleting at Kth of Circular Link List
{
    if(head==NULL)
        return head;
    if(k==1)
        return delHead(head);
    Node* curr=head;
    for(int i=0;i<k-2;i++)\
        curr=curr->next;
    Node* temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}

void nprint(Node *head)//print circular Link List
{
    if(head==NULL)
        return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    nprint(head);

    return 0;
}

