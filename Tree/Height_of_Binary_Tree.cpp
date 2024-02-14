#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node (int k)
    {
        key=k;
        left=right=NULL;
    }
};

int height(Node *root)
{
    if(root==NULL)
        return 0;
    else
        return max(height(root->left),height(root->right))+1;
}

int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(8);
    root->left->right=new Node(7);
    root->right->right=new Node(6);
    root->left->right->left=new Node(9);
    root->left->right->right=new Node(15);
    cout<<"Height: ";
    cout<<height(root);
    return 0;
}