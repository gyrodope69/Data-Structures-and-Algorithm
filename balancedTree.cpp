#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

int height(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int lh = height(root->left);
  int rh = height(root->right);

  return max(lh, rh) + 1;
}

// bool balancedTree(Node *root)
// {
//   if (root == NULL)
//   {
//     return true;
//   }

//   if (balancedTree(root->left) == false)
//   {
//     return false;
//   }
//   if (balancedTree(root->right) == false)
//   {
//     return false;
//   }
//   int lh = height(root->left);
//   int rh = height(root->right);

//   if (abs(lh - rh) <= 1)
//   {
//     return true;
//   }
//   else
//   {
//     return false;
//   }
// }
bool balancedTree(Node* root , int *height)
{
  if (root == NULL)
  {
    return true;
  }
  int lh=0, rh=0;
    if(balancedTree(root->left, &lh) == false)
    {
       return false; 
    }
    
    if(balancedTree(root->right, &rh) == false)
    {
      return false;
    }

    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    {
      return true;
    }
    else {
      return false;
    }

}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  // root->right = new Node(3);
  root->left->left = new Node(4);
  // root->left->right = new Node(5);
  // root->right->left = new Node(6);
  // root->right->right = new Node(7);
  // cout << balancedTree(root) << endl;
  int height = 0;
  if(balancedTree(root,&height))
  {
    cout<<"balanced tree";
  }
  else
  {
    cout<<"not balanced tree";
  }
  return 0;
}