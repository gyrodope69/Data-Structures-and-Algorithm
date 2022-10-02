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

Node* consturctBST(int preorder[], int* preorderIdx , int key , int min , int max , int n)
{
    if(*preorderIdx>=n)
    {
        return NULL; 
    }

    Node* root = NULL;
    if(key>min && key<max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx+1;
        if(*preorderIdx<=n)
        {
            root->left=consturctBST(preorder , preorderIdx ,preorder[*preorderIdx] , min , key , n);
        }
        if(*preorderIdx<=n)
        {
            root->right=consturctBST(preorder , preorderIdx , preorder[*preorderIdx] ,key , max , n);
        }
    }
    return root;
}

void printPreOrder(Node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
int main()
{
    /*
        10
       /  \
      2   13
     /    /
    1    11
    */
  int preorder[] = {10,2,1,13,11};
  int n = 5;
  int preorderIdx = 0;
  Node* root = consturctBST(preorder,&preorderIdx,preorder[0] , INT_MIN, INT_MAX ,5);
  printPreOrder(root);
  return 0;
}