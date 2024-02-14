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

bool isBalanced1(Node *root)
{
    if(root==NULL)
        return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return (abs(lh-rh)<=1 && isBalanced1(root->left) && isBalanced1(root->right));
}

int isBalancedWithHeight(Node *root)
{
    if(root==NULL)
        return 0;
    int lh=isBalancedWithHeight(root->left);
    if(lh==-1)
        return -1;
    int rh=isBalancedWithHeight(root->right);
    if(rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    else    
        return max(lh,rh)+1;
}

int main()
{
    Node *root=new Node(18);
    root->left=new Node(4);
    root->right=new Node(20);
    root->right->left=new Node(13);
    root->right->right=new Node(70);
    cout<<isBalanced1(root);
    cout<<endl;
    cout<<"Height: "<<isBalancedWithHeight(root);
    return 0;
}