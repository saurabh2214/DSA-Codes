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

void rPrintPre(Node *root)  //Preorder Traversal
{
    if(root!=NULL){
    cout<<root->key<<" ";
    rPrintPre(root->left);
    rPrintPre(root->right);
    }
}

void rPrintIn(Node *root)  //Inorder Traversal
{
    if(root!=NULL){
    rPrintIn(root->left);
    cout<<root->key<<" ";
    rPrintIn(root->right);
    }
}

void rPrintPost(Node *root)  //Postorder Traversal
{
    if(root!=NULL){
    rPrintPost(root->left);
    rPrintPost(root->right);
    cout<<root->key<<" ";
    }
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
    cout<<"DFS(Preorder): ";
    rPrintPre(root);
    cout<<endl;
    cout<<"DFS(Inorder): ";
    rPrintIn(root);
    cout<<endl;
    cout<<"DFS(Postorder): ";
    rPrintPost(root);
    cout<<endl;
    return 0;
}