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

void itInorder(Node *root)
{
    if(root==NULL)
        return;
    stack<Node *> st;
    Node *curr=root;
    while(curr!=NULL || st.empty()==false)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}

void itPreorder(Node *root)
{
    if(root==NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while(st.empty()==false)
    {
        Node *curr=st.top();
        cout<<curr->key<<" ";
        st.pop();
        if(curr->right!=NULL)
            st.push(curr->right);
        if(curr->left!=NULL)
            st.push(curr->left);
    }
}

void itPostorder(Node *root)
{
    if(root==NULL)
        return;
    stack<Node *> st;
    Node *curr=root;
    while(curr!=NULL || st.empty()==false)
    {
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            if(curr->right!=NULL)
                st.push(curr->right);
            curr=curr->left;
        }
        if(st.empty()==false)
        {
            curr=st.top();
            st.pop();
        }
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
    cout<<"BFS(Inorder): ";
    itInorder(root);
    cout<<endl;
    cout<<"BFS(Preorder): ";
    itPreorder(root);
    cout<<endl;
    cout<<"BFS(Postorder): ";
    itPostorder(root);
    return 0;
}