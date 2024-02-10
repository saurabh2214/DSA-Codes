#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    Node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

Node *insertR(Node *root,int x)
{
    if(root==NULL)
        return new Node(x);
    else if(root->key>x)
        root->left= insertR(root->left,x);
    else if(root->key<x)
        root->right=insertR(root->right,x);
}

Node *insertI(Node *root,int x)
{
    Node *temp=new Node(x);
    Node *parent=NULL;
    Node *curr=root;
    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else 
            return root;
    }
    if(parent==NULL)
        return temp;
    if(parent->key>x)
        parent->left=temp;
    else    
        parent->right=temp;
    return root;
}



int main()
{
    Node *root= new Node(8);
    insertR(root,2);
    insertI(root,10);
    return 0;
}