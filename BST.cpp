#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
      data = val;
      left = NULL;
      right = NULL;
    } 
};
Node* insertNode(Node* root , int val)
{
  if(root == NULL)
  {
    return new Node(val);
  }

  if(val<root->data)
  {
    root->left = insertNode(root->left , val);
  }
  else
  {
    root->right = insertNode(root->right , val);
  }

  return root;
}

void printInorder(Node* root)
{
    if(root==NULL){
     return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main()
{
    Node* root = NULL;
    root = insertNode(root,5);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,1);
    insertNode(root,7);
    printInorder(root);
    return 0;
}