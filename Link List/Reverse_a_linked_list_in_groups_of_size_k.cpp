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

Node *reverseKrec(Node *head,int k) //Recursive Method
{
    Node *curr=head,*next=NULL,*prev=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        Node *rest_head=reverseKrec(next,k);
        head->next=rest_head;
    }
    return prev;
}

Node *reverseKIT(Node *head,int k)  //Iterative Method
{
    Node *curr=head,*prevFirst=NULL;
    bool isFirstPass=true;
    while(curr!=NULL){
        Node *first=curr,*prev=NULL;
        int count=0;
        while(curr!=NULL&&count<k){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
        }
        if(isFirstPass){head=prev;isFirstPass=false;}
        else{prevFirst->next=prev;}
        prevFirst=first;
    }
    return head;
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	head->next->next->next->next->next=new Node(60);
	head->next->next->next->next->next->next=new Node(70);
	printlist(head);
	head=reverseKrec(head,3);
	printlist(head);
    head=reverseKIT(head,3);
	printlist(head);
	return 0;
} 
