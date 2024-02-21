#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

void printNthFromEndLength(Node * head,int n)  //Using length of Linked List
{
    int len=0;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
        len++;
    if(len<n)
        return;
    Node *curr=head;
    for(int i=1;i<len-n+1;i++)
        curr=curr->next;
    cout<<(curr->data)<<" ";
}

void printNthFromEndPointer(Node * head,int n) //Using Two Pointers/References
{
    if(head==NULL)return;
    Node *first=head;
    for(int i=0;i<n;i++){
        if(first==NULL)return;
        first=first->next;
    }
    Node *second=head;
    while(first!=NULL){
        second=second->next;
        first=first->next;
    }
    cout<<(second->data);
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	printlist(head);
	cout<<"Nth node from end of Linked List Using length of Linked List : ";
	printNthFromEndLength(head,2);
    cout<<endl;
    cout<<"Nth node from end of Linked List Using Two Pointers/References : ";
	printNthFromEndPointer(head,2);

	return 0;
} 
