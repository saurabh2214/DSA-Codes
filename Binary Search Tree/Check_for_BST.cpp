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

bool isBSTB(Node* root,int min, int max)  
{  
  if (root == NULL)  
    return true;  
      
  return ( root->key>min && root->key<max && 
            isBSTB(root->left,min,root->key) && isBSTB(root->right,root->key,max));  
}


int prevv=INT_MIN;
bool isBSTA(Node* root)  
{  
    if (root == NULL)  
        return true;  
    
    if(isBSTA(root->left)==false)return false;
    
    if(root->key<=prevv)return false;
    prevv=root->key;
    
    return isBSTA(root->right);
}


int main() {
	
	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBSTB(root,INT_MIN,INT_MAX))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  

        cout<<endl;

    if(isBSTA(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    
    return 0;  
	
}