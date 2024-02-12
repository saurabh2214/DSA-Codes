#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left;
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void vsumR(Node *root,int hd,map<int,int> &mp)
{
    if(root==NULL)return;
    vsumR(root->left,hd-1,mp);
    mp[hd]+=root->key;
    vsumR(root->right,hd+1,mp);
}

void vSum(Node *root)
{
    map<int,int> mp;
    vsumR(root,0,mp);
    for(auto it:mp)
        cout<<it.second<<" ";
}

int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(50);  
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    
    vSum(root);
          
    return 0;  
	
}