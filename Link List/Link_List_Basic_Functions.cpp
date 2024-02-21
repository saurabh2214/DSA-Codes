#include <iostream>

using namespace std;

struct Node //creating a structure for making of link list
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

Node *insertBegin(Node *head , int x) //This Function is use to insert element from beginning
{
    Node*temp = new Node(x);
    temp->next=head;
    return temp;
}

Node *insertEnd(Node *head , int x) //This Function is use to insert element from end
{
    Node*temp = new Node(x);
    if(head==NULL)
        return temp;
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    return head;
}

Node *insertPos(Node *head , int pos ,int data) //This Function is use to insert element from any specific postion
{
    Node *temp = new Node(data);
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    for(int i=1;i<=pos-2 && curr!=NULL;i++)
        curr=curr->next;
    if(curr==NULL)
        return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

int SearchIT(Node *head , int x)//Iterative Search in Link List
{
    int pos=1;
    Node *curr = head;
    while(curr!=NULL)
    {
        if(curr->data==x)
            return pos;
        else
        {
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}

int SearchRC(Node *head , int x)//Recursive Search in Link List
{
    if(head == NULL)
        return -1;
    if(head->data==x)
        return 1;
    else
    {
        int res=SearchRC(head->next,x);
        if(res==-1)
            return -1;
        else
            return (res+1);
    }
}

Node *delHead(Node *head) //This function is use to delete the first node of link list
{ 
    if(head==NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node *delTail(Node *head) //This function is use to delete the Last node of link list
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next!=NULL)
        curr=curr->next;
    delete (curr->next);
    curr->next=NULL;
    return head;
}

void rPrint(Node *head) //This Function is use to print any link list 
{
    if(head == NULL)
        return;
    cout<<(head->data)<<" ";
    rPrint(head->next);
}



int main()
{
    Node *head = NULL;
    //Insertion from beginning
    head=insertBegin(head,30);
    head=insertBegin(head,20);
    head=insertBegin(head,10);
    rPrint(head);
    cout<<endl;
    
    //Insertion from end
    head=insertEnd(head,40);
    head=insertEnd(head,50);
    head=insertEnd(head,60);
    rPrint(head);
    cout<<endl;
    
    //Inserting from any specific postion
    head=insertPos(head,2,15);
    head=insertPos(head,4,25);
    head=insertPos(head,6,35);
    head=insertPos(head,8,45);
    head=insertPos(head,10,55);
    rPrint(head);
    cout<<endl;
    
    //Searching element from the Link List using iteration
    cout<<SearchIT(head,40);
    cout<<SearchIT(head,44);
    cout<<endl;
    
    //Searching element from the Link List using recursion
    
    cout<<SearchRC(head,30);
    cout<<SearchRC(head,34);
    cout<<endl;
    
    //Deleting a First Node of the Link List
    head=delHead(head);
    head=delHead(head);
    head=delHead(head);
    rPrint(head);
    cout<<endl;
    
    //Deleting a Last Node of the Link List
    head=delTail(head);
    head=delTail(head);
    head=delTail(head);
    rPrint(head);
    cout<<endl;
    

    return 0;
}

