#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int k)
    {
        data=k;
        next=NULL;
    }
};

Node* sortInserted(Node* head, int x)
{
    Node* temp=new Node(x);
    if(head==NULL)
        return temp;
    if(x<head->data)
    {
        temp->next=head;
        return temp;
    }
    Node* curr=head;
    while(curr->next!=NULL && curr->next->data<x)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

void rPrint(Node *head) 
{
    if(head == NULL)
        return;
    cout<<(head->data)<<" ";
    rPrint(head->next);
}

int main()
{
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    int x=25;
    rPrint(head);
    cout<<endl;
    head=sortInserted(head,x);
    rPrint(head);
    return 0;
}